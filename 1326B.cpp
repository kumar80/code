#include<bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define LL long long 
#define mod 998244353 
#define FOR(i, j, k) for (int i=j ; i<k ; i++)
#define ROF(i, j, k) for (int i=j ; i>=k ; i--) 
 
const long long INF = 1e18; 
const long long MAX = 1e5+10;

int main(){
    fastio;
    int n; cin>>n;
    int b[n],a[n],x[n]; FOR(i,0,n) cin>>b[i];
    x[0]=0;a[0]=b[0];
    int m=a[0];
    FOR(i,1,n) {
        a[i] = b[i]+m;
        m=max(a[i],m);
    }
    FOR(i,0,n) cout<<a[i]<<" ";
}