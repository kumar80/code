#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

void multiply(ll F[2][2], ll M[2][2]);

void power(ll F[2][2], ll n);


ll fib(ll n)
{
  ll F[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  power(F, n-1);
  return F[0][0];
}

void power(ll F[2][2], ll n)
{
  if( n == 0 || n == 1)
      return;
  ll M[2][2] = {{1,1},{1,0}};

  power(F, n/2);
  multiply(F, F);

  if (n%2 != 0)
     multiply(F, M);
}

void multiply(ll F[2][2], ll M[2][2])
{
  ll x =  (F[0][0]*M[0][0] + F[0][1]*M[1][0])%MOD;
  ll y =  (F[0][0]*M[0][1] + F[0][1]*M[1][1])%MOD;
  ll z =  (F[1][0]*M[0][0] + F[1][1]*M[1][0])%MOD;
  ll w =  (F[1][0]*M[0][1] + F[1][1]*M[1][1])%MOD;

  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}

unsigned long long power(unsigned long long x, 
                                  ll y, ll p)
{
    unsigned long long res = 1; 
 
    x = x % p; 
 
    while (y > 0) 
    {
    
        if (y & 1)
            res = (res * x) % p;
 
        y = y >> 1; 
        x = (x * x) % p;
    }
    return res;
}
 
unsigned long long modInverse(unsigned long long n,  
                                            ll p)
{
    return power(n, p - 2, p);
}
 

unsigned long long nCrModPFermat(unsigned long long n,
                                 int r, ll p)
{
    
    if (n < r)
        return 0;
   
    if (r == 0)
        return 1;
 
    
    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
 
    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}

int main(){
    
    int v, m, x;
    cin>>v>>m>>x;
    
    unsigned long long ans = 0;
    for(int i = m + 2; i <= x + 2; i++){
        ll val = fib(i) % 1000000007;
        if(val < v)
            continue;
        ans += nCrModPFermat(val, v, 1000000007);
    }
    
    cout<<ans<<'\n';
    
    return 0;
}