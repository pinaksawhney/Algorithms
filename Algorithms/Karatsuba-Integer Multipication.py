# karatsuba algorithm for integer multipication using gauss's trick and recursive approach

import math


def divide_nums(x):
    len_x = len(x)
    a = int(x[:len_x/2])
    b = int(x[len_x/2:])
    return a, b


def recursive_multipication(x, y, n):
    ans = 0
    len_x = len(str(x))
    len_y = len(str(y))
    if len_x != len_y:
        X = "0"*abs(len_y-len_x) + str(min(x, y))
        Y = str(max(x, y))
    else:
        X = str(x)
        Y = str(y)
    if n == 1:
        ans += int(X)*int(Y)
    else:
        a, b = divide_nums(X)
        c, d = divide_nums(Y)
        one = recursive_multipication(a, c, max(len(str(a)), len(str(c))))
        two = recursive_multipication(b, d, max(len(str(b)), len(str(d))))
        three = recursive_multipication(a+b, c+d, max(len(str(a+b)), len(str(c+d))))      # gauss' trick
        if n%2 == 0:
            ans += (10**n)*one + 10**(n/2)*(three-one-two) + two
        else:
            ans += (10**(n+1))*one + 10**(int(math.ceil(n/2.0)))*(three-one-two) + two
    return ans


if __name__ == '__main__':
    x = int(raw_input("First integer: "))
    y = int(raw_input("Second integer: "))
    print recursive_multipication(x, y, max(len(str(x)), len(str(y))))
