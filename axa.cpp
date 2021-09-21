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
    int t=1; //cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        bool o[n+1][3];
        FOR(i,0,n+1) o[i][1] = o[i][2] = false;
        FOR(i,0,k) {
            int x,y;
            cin>>x>>y;
            o[x][y] = 1;
        }
        LL dp[n+1][3];
        dp[0][1] = dp[0][2] = 0;
        FOR(i,1,n+1){
            dp[i][1]  = dp[i-1][1] + ( o[i][1] ? 1 + dp[i-1][1] : 1);
            dp[i][2]  = dp[i-1][2] + ( o[i][2] ? 1 + dp[i-1][2] : 1);             
        }
        if(dp[n][1]<dp[n][2]) cout<<"First";
        else if(dp[n][1]>dp[n][2]) cout<<"Second";
        else cout<<"Draw";
    }
}
