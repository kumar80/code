//https://codeforces.com/contest/1323/problem/B
#include<bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define LL long long 
#define mod 998244353 
#define FOR(i, j, k) for (int i=j ; i<k ; i++)
#define ROF(i, j, k) for (int i=j ; i>=k ; i--) 
 
const long long INF = 1e18;
const long long MAX = 1e5+10;

int main()//https://codeforces.com/contest/1323/problem/B
{
    fastio;
    int n,m,k; cin>>n>>m>>k;
    LL a[n],b[m],r[n+1]={0},c[m+1]={0};
    FOR(i,0,n) cin>>a[i]; 
    FOR(i,0,m) cin>>b[i];
    int i=0;
    while(i<n){
        int j=i;
        while(j<n && a[j]==1) j++;
        int len = j-i;
        FOR(k,1,j-i+1){
            r[k]+=len;
            len--;
        }
        i=j+1;
    }i=0;
    while(i<m){
        int j=i;
        while(j<m && b[j]==1) j++;
          int len = j-i;
        FOR(k,1,j-i+1){
            c[k]+=len;
            len--;
        }
        i=j+1;
    }LL ans = 0;

    FOR(i,1,n+1){
        if(k%i==0 && k/i<=m){
            ans+= r[i]*c[k/i];
        }
    }
//https://codeforces.com/contest/1323/problem/B
    cout<<ans;
}