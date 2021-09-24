# use Python 3
# this script simply returns a binary representation of a decimal number

count = 0

def binary(n):
    global count
    count = count + 1
    if n == 0:
        return ""
    else:
        return (binary(n//2) + str(n%2))

n = 2
asdf = binary(n)
print("Decimal:", n, "\nBinary:", asdf, "\nAfter", count, "recursions")
