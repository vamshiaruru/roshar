numbers = map(int, raw_input().split())
n = numbers[0]
p = numbers[1]
x = numbers[2]
A = map(int, raw_input().split())
maxScore = 0
id = 1
for i in xrange(len(A)):
    if A[i]*p > maxScore:
        maxScore = A[i] * p
        id = i + 1;
    p = p - x

print id
