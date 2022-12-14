import numpy as np



input = open('day14.txt', 'r')
input = input.readlines()

begin = 400
bottom = 200

cave = np.zeros((bottom + 1, (500-begin)*2))

for i in range(len(input)):
    input[i] = input[i].replace("->", ",")
    input[i] = input[i].replace("\n", "")
    input[i] = input[i].replace(" ", "")


rocks = [eval(input[i]) for i in range(len(input))]

for i in range(len(rocks)):
    for j in range(int(len(rocks[i])/2)-1):
        if rocks[i][j*2] != rocks[i][j*2+2]:
            for k in range(abs(rocks[i][j*2] - rocks[i][j*2+2])+1):
                cave[rocks[i][j*2+1]][min(rocks[i][j*2], rocks[i][j*2+2]) + k - begin] = 1
        else:
            for k in range(abs(rocks[i][j*2+1] - rocks[i][j*2+3])+1):
                cave[min(rocks[i][j*2+1], rocks[i][j*2+3])+k][rocks[i][j*2]-begin] = 1

print(cave)
  
abyss = False
units = 0
while not abyss:
    x = 500
    y = 0
    units += 1
    while True:
        if cave[y+1][x-begin] == 0:
            y += 1
        elif cave[y+1][x-begin-1] == 0:
            y += 1
            x -= 1
        elif cave[y+1][x-begin+1] == 0:
            y += 1
            x += 1
        else:
            cave[y][x-begin] = 1
            break
        if y >= bottom:
            abyss = True
            break
    #print(cave)

print(units - 1)      