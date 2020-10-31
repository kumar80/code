N = float(input())
M = str(N)
M = list(map(int, M.split(".")))
if(M[0] == 10 and M[1] <= 22):
    print("INVALID INPUT")
elif(((M[0] >= 0 and M[0] <= 23) and (M[1] <= 0 and M[1] <= 58))):
    print("{:.2f} {:.2f} {:.2f} {:.2f} {:.2f} {:.2f}".format(
        N, N+0.04, N+0.09, N+0.15, N+0.18, N+0.23))
else:
    print("INVALID INPUT")
