a = b = c = 0
d = []

while(1):
    n = input()
    if n.isdigit() == True:
        d.append(int(n))
    else:
        break

for i in d:
    if i > 0 and i < 17:
        a += 1
    if i >= 17 and i < 40:
        b += 1
    if i >= 40 and i < 120:
        c += 1
t = a*200+b*400+c*300
print("Total Income: ", t, "INR")
