def move(pos, char):
    if char == 'U':
        pos[1] += 1
    elif char == 'D':
        pos[1] -= 1
    elif char == 'L':
        pos[0] -= 1
    else:
        pos[0] += 1
    return pos

def traverse(instruction, destination):
    instructions = list(instruction)
    init = [0, 0]
    count = 0
    while True:
        for i in instructions:
            init = move(init, i)
            count = count + 1
            if init == destination:
                return True
            if (count/len(instructions)) == 100000:
                return False

destination = map(int, raw_input().split())
instruction = raw_input()
if traverse(instruction, destination):
    print "Yes"
else:
    print "No"