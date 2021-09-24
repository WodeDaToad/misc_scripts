# use Python 3
# I wrote this to manage files on my computer and move them around

import os
import shutil
import time

'''
notes on my thinking

copyfiles(){
    iterate through files in A{
        file in A exists
        if file exists in B{
            if A and B are the same{
                ok
            }else{
                report difference
            }
        }else{
            copy file to B
        }
    }
}
'''

def log(content, file):
    print(content)
    with open(file, "a") as f:
        f.write(content)
        f.write("\n")

def copyfiles(fro, to, file="addfiles.txt", mode=0):
    count = 0

    # all content in A
    for root, dirs, files in os.walk(fro):
        newroot = root.replace(fro, to)

        # is this an exempted folder?
        paas = False
        for elem in exempt:
            if root.find(elem) != -1:
                paas = True
                break

        # does this root exist?
        if not os.path.isdir(root):
            paas = True

        if paas:
            log("Passing over " + root, file)
            continue

        # check directories in A
        for name in dirs:
            # is this an exempted folder?
            if name in exempt:
                log("Passing over " + name, file)
                continue

            # fill in missing directories
            current = root + os.sep + name
            compare = newroot + os.sep + name
            if os.path.isdir(compare):
                log("PATH " + compare + " +FOUND+", file)
            else:
                log("PATH " + compare + " -NOT FOUND-", file)
                if mode == 1:
                    os.mkdir(compare)
                    log("Created " + compare, file)
                elif mode == -1:
                    shutil.rmtree(current)
                    log("Deleted " + current, file)

        # check files in A
        for name in files:
            # is this an exempted file?
            if name in exempt:
                log("Passing over " + name, file)
                continue

            current = root + os.sep + name
            compare = newroot + os.sep + name

            # does B exist?
            if os.path.isfile(compare):
                log("FILE " + compare + " +FOUND+", file)

                # note differences in file size
                if os.path.getsize(current) != os.path.getsize(compare):
                    log("    Difference found:", file)
                    log("    " + current + str(os.path.getsize(current)), file)
                    log("    " + compare + str(os.path.getsize(compare)), file)

            # copy missing files from A to B
            else:
                log("FILE " + compare + " -NOT FOUND-", file)
                if mode == 1:
                    log("Copying " + str(os.path.getsize(current)) + " bytes...", file)
                    shutil.copy2(current, compare)
                    log("Copied " + current + " to " + compare, file)
                    count += os.path.getsize(current)
                elif mode == -1:
                    log("Deleting " + str(os.path.getsize(current)) + " bytes...", file)
                    os.remove(current)
                    log("Deleted " + current, file)

    # return the difference in bytes
    return count

# copy all files in A to B
# copy all files in B to A
def consolidatefiles(fro, to, file="consolidatefiles.txt"):
    f = open(file, "w")
    f.close
    start = time.time()
    count = copyfiles(fro, to, file, 1)
    count += copyfiles(to, fro, file, 1)
    end = time.time()
    log("Finished: Copied " + str(count) + " bytes", file)
    log("Took " + str(end - start) + " seconds", file)

# same as consolidatefiles
# minus the part where it actually copies files
# use to compare folder contents
def comparefiles(fro, to, file="comparefiles.txt"):
    f = open(file, "w")
    f.close
    start = time.time()
    count = copyfiles(fro, to, file, 0)
    count += copyfiles(to, fro, file, 0)
    end = time.time()
    log("Finished: Didn't copy " + str(count) + " bytes", file)
    log("Took " + str(end - start) + " seconds", file)

# B will be an image of A
def castfiles(fro, to, file="castfiles.txt"):
    f = open(file, "w")
    f.close
    start = time.time()
    copyfiles(to, fro, file, -1)
    count = copyfiles(fro, to, file, 1)
    end = time.time()
    log("Finished: Copied " + str(count) + " bytes", file)
    log("Took " + str(end - start) + " seconds", file)

# copy all files in A to B
def pullfiles(fro, to, file="pullfiles.txt"):
    f = open(file, "w")
    f.close
    start = time.time()
    count = copyfiles(fro, to, file, 1)
    end = time.time()
    log("Finished: Copied " + str(count) + " bytes", file)
    log("Took " + str(end - start) + " seconds", file)

def main():
    fro = "D:\\Red\\FMP\\"
    to = "F:\\FMP\\"
    castfiles(fro, to)

# exempt files will be passed over
exempt = ["exempt_folder"]

if __name__ == "__main__":
    main()
