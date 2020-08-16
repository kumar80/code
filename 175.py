import getch

A = 0
c = [5,6]
B = 0
co = skips = 0
if(c[-1] < 0):
    co = -1
else:
    for i in c:
        if(skips > B):
            break
        else:
            if(i < 0):
                skips += i
                continue
        co += i


import math
n=int(input())
l = [[0 for x in range(n)] for y in range(n)] 
c=0
for i in range(n):
    for j in range(n):
        char = getch.getch()
        l[i][j]=char;

for j in range(n):
    for k in range(n):
        if l[j][k]=='D':
            c+=1
print(math.floor(math.sqrt(c)))