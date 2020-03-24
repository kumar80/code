#include<bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define LL long long 
#define mod 998244353 
#define FOR(i, j, k) for (int i=j ; i<k ; i++)
#define ROF(i, j, k) for (int i=j ; i>=k ; i--) 
 
const long long INF = 1e18;
const long long MAX = 1e5+10;
LL fme(int x, int y){
    LL res = 1;
    while(y){
        if(y&1) res = (res*x)%mod;
        y/=2;
        x=(x*x)%mod;
    }
    return res;
}

LL gcdextended(LL a, LL b, LL *x, LL *y){
    if(a==0) {
        *x=0;*y=1;
        return b;
    }
    LL x1,y1;
    LL g = gcdextended(b%a, a, &x1, &y1); 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
    return g;
}

LL invmod(LL c){
    LL x,y;
    LL g = gcdextended(c,mod,&x,&y); 
    return (x%mod + mod)%mod;
}

int main(){
    int n,m; cin>>n>>m;
    LL f[2*MAX];f[0]=1;f[1]=1;
    FOR(i,2,2*MAX) f[i]=(i*f[i-1])%998244353; 
    LL mcr = (f[m]*invmod( (f[n-1]*f[m-n+1])%mod ))%mod;
    LL ans = (mcr*(n-2))%mod;
    LL e = fme(2,n-3);
    ans = (ans*e)%mod;
    cout<<ans;
}