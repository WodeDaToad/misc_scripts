# use Python 3
# this is just an insertion sort

def insertionsort(lis):
    result = lis
    for i in range(len(result)):
        current = result[i]
        position = i - 1
        compare = result[position]
        while position >= 0 and current < compare:
            result[position + 1] = result[position]
            position -= 1
            compare = result[position]
        result[position + 1] = current
    return result

asdf = [1, 4, 3, 2, 6, 5]
asdfg = insertionsort(asdf)
print(asdfg)
        
