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
print(co)
