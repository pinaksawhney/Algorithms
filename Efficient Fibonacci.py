# naive recursive approach O(2**n)


def fib(n):
    if n == 1 or n == 2:
        result = 1
    else:
        result = fib(n-1)  + fib(n-2)
    return result


# dynamic programing - memoized version O(n)

memo = [0]*1001


def fib_mem(n):
    if memo[n] != 0:
        return memo[n]
    else:
        if n == 1 or n == 2:
            result = 1
        else:
            result = fib_mem(n-1) + fib_mem(n-2)
        memo[n] = result
        return result


# dynamic programing - bottom-up approach O(n)

bottom = 10001*[0]


def fib_bottom(n):
    if n == 1 or n == 2:
        return 1
    bottom[1] = 1
    bottom[2] = 1
    for i in range(3,n+1):
        bottom[i] = bottom[i-1] + bottom[i-2]
    return bottom[n]


print fib_bottom(35)
print fib_bottom(100)
print fib_bottom(1000)
print fib_bottom(10000)
