#include<bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define LL long long 
#define mod 1000000007 
#define all(v) v.begin(),v.end()
#define FOR(i, j, k) for (auto i=j ; i<k ; i++)
#define ROF(i, j, k) for (auto i=j ; i>=k ; i--) 
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false); debug("%s time : %.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))

const long long INF = 1e18;
const long long MAX = 1e5+10;
int main(){
    fastio;
    int t=1;// cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        int a[n+1][m+1]; 
        FOR(i,1,n+1) FOR(j,1,m+1) cin>>a[i][j];
        int x,y; cin>>x>>y;
        vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MAX));
        dp[0][1] = 0;
        FOR(i,1,n+1) dp[i][1] = dp[i-1][1] + a[i][1]; 
        FOR(i,2,n+1)
            FOR(j,2,m+1) 
                dp[i][j] = min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]}) + a[i][j];

        cout<<dp[x+1][y+1];
    }
}
