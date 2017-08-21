def multiply(lo, hi):
    if lo+1 < hi:
        mid = (hi + lo)/2
        return multiply(lo, mid) * multiply(mid+1, hi)
    if lo == hi:
        return lo
    return lo*hi

def factorial(num):
    if num < 2:
        return 1
    return multiply(1, num)

def gcd(a ,b):
    if a < b:
        return factorial(a)
    return factorial(b)

numbers = map(int, raw_input().split())
print gcd(numbers[0], numbers[1])
