# karatsuba algorithm for integer multipication using recursive approach [where x and y has equal no of digits]

from datetime import datetime

def divide_nums(x):
    x = str(x)
    len_x = len(x)
    if len_x > 1:
        if len_x % 2 == 0:
            a = int(x[:len_x/2])
            b = int(x[len_x/2:])
        else:
            a = int(x[:len_x/2+1])
            b = int(x[len_x/2+1:])
    else:
        a = x
        b = 0
    return a, b


def recursive_multipication(x, y, n):
    ans = 0
    if n == 1:
        ans += int(x)*int(y)
    else:
        a, b = divide_nums(x)
        c, d = divide_nums(y)
        one = recursive_multipication(a, c, min(len(str(a)), len(str(c))))
        two = recursive_multipication(a, d, min(len(str(a)), len(str(d)))) + recursive_multipication(b, c,min(len(str(b)),len(str(c))))
        three = recursive_multipication(b, d, min(len(str(b)), len(str(d))))
        if n%2==0:
            ans += (10 ** n) * one + (10 ** (n / 2)) * two + three
        else:
            ans += (10 ** (n-1)) * one + (10 ** (n / 2)) * two + three

    return ans


if __name__ == '__main__':
    x = raw_input("Enter first integer x: ")
    y = raw_input("Enter second integer y: ")
    t1 = datetime.now()
    print recursive_multipication(x, y, len(str(x)))
    t2 = datetime.now()
    delta = t2-t1
    print delta.microseconds

