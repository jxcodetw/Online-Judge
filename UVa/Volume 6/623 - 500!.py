import math
while True:
    try:
        n = int(input())
        print("{0}!".format(n))
        print(math.factorial(n))
    except EOFError:
        break
