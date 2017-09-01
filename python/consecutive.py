def maxConsecutiveOnes(binary):
    maxi = 0
    curr = 0
    for i in xrange(len(binary)):
        if binary[i] == '1':
            curr = curr + 1
        else:
            maxi = max(maxi, curr)
            curr = 0
    return max(maxi, curr)         

n = int(raw_input().strip())
binary = bin(n)[2:]
print maxConsecutiveOnes(binary)