def hourGlassSum(arr,i,j):
    summ = 0
    l = [(i,j),(i-1,j-1),(i-1,j),(i-1,j+1),(i+1,j-1),(i+1,j),(i+1,j+1)]
    for p,q in l:
        summ = summ + arr[p][q]
    return summ

arr = []
for arr_i in xrange(6):
   arr_temp = map(int,raw_input().strip().split(' '))
   arr.append(arr_temp)
maxi = -9999
curr = 0
for i in range(1,5):
    for j in range(1,5):
        curr = hourGlassSum(arr, i,j)
        maxi = max(maxi,curr)
print maxi