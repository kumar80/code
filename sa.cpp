#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
ll a,b,c,d;
ll power(ll x,ll n)
{
    ll result=1;
    while(n)
    {
        if(n&1)
            result=(result * x)%MOD;
        x=(x*x)%MOD;
        n=n>>1;
    }
    return result;
}

void fast_fib(long long int n,long long int ans[])
{
    if(n == 0)
    {
        ans[0] = 0;
        ans[1] = 1;
        return;
    }
    fast_fib((n/2),ans);
    a = ans[0];             /* F(n) */
    b = ans[1];             /* F(n+1) */
    c = 2*b - a;
    if(c < 0)
        c += MOD;
    c = (a * c) % MOD;      /* F(2n) */
    d = (a*a + b*b) % MOD;  /* F(2n + 1) */
    if(n%2 == 0)
    {
        ans[0] = c;
        ans[1] = d;
    }
    else
    {
        ans[0] = d;
        ans[1] = c+d;
    }
}
int main(){
    ll v,x,y,i,j;
    cin>>v>>x>>y;
    long long int ans[2]={0};
    fast_fib(x,ans);
    a=ans[0];
    b=ans[1];
    ll t=0;
    for(i=x;i<=y;i++){
        c=a+b;
        ll k=1;
        a=b;
        b=c;
        if(c<v)
        continue;
        for(j=0;j<v;j++){
            k*=(c-j);
            k%=MOD;
        }
        t+=k;
        t%=MOD;
    }
    ll z=1;
    for(i=1;i<=v;i++){
        z*=(power(i,MOD-2));
        z%=MOD;
    }
    t*=z;
    t%=MOD;
    cout<<t;
    return 0;
}