n = input()
mx=[-1 for x in range(1)] 
for i in range(n-1,0,-1):
    mx[i]=max(a[i],mx[i+1])

ans = 0
for i in range(0,n):
    ans=max(ans,mx[i]-a[i])

print(ans)