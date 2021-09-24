# use Python 3

#primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]

# find all prime numbers in range from 0 to count
def findprimes(count):
    primes = []
    for x in range(count):
        isprime = True
        if x == 0 or x == 1:
            continue
        elif x == 2:
            pass
        else:
            for y in primes:
                asdf = x / float(y)
                if x / float(y) == x / y:
                    isprime = False
                    break
                else:
                    continue
        if isprime:
            primes.append(x)
    return primes

# returns a greatest common denominator
def findgcd(num1, num2):
    print('gcd(', num1, num2, ')')
    if num2 == 0:
        return num1
    count = 0
    while True:
        b = num2 * count
        remain = num1 - b
        if remain < num2:
            break
        count += 1
    return findgcd(num2, remain)

# returns a greatest common denominator but faster
def findgcdbetter(a, b):
    print('gcdbetter(', a, b, ')')
    if b == 0:
        return a
    else:
        r = a % b
        return findgcdbetter(b, r)

# find lowest common multiple
def findlcm(a, b):
    x = a * b
    y = findgcdbetter(a, b)
    return x / y


print(findgcdbetter(1953, 1937))
