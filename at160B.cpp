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
    int n,x,y; cin>>n>>x>>y;
    map<int,int>m; 
    FOR(i,1,n+1){
        FOR(j,i+1,n+1){
           int d = min(abs(y-j)+abs(x-i)+1,abs(j-i));
           m[d]++; 
        }
    }
    FOR(i,1,n) cout<<m[i]<<"\n";
}