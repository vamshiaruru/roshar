"""
A practice python program. Nothing more. Shoo
"""
n = int(raw_input())
count = 0
j=0
for i in xrange(n):
    temp = 0
    k = map(lambda x: int(x), raw_input().split())
    for num in k:
        if num == 1 :
            temp = temp + 1
    if temp >= 2:
        count = count + 1

print count
