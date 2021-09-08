#include<bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define LL long long 
#define mod 100000000 
#define FOR(i, j, k) for (int i=j ; i<k ; i++)
#define ROF(i, j, k) for (int i=j ; i>=k ; i--) 
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false); debug("%s time : %.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))

const long long INF = 1e18;
const long long MAX = 1e5+10;
int main(){
    fastio;
    int t=1; cin>>t;
    while(t--){
       int n; cin>>n;
       LL dp[n+1];
       dp[0]=dp[1]=0; dp[2]=1;
       for(int i=3;i<=n;i++) 
        if(i&1) dp[i] = dp[i-1];
        else dp[i] = dp[i-2] * (i-2);
       cout<<dp[n]<<"\n";
    }
}