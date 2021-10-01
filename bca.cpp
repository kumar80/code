#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
#define LL long long
#define mod 998244353
#define FOR(i, j, k) for (int i = j; i < k; i++)
#define ROF(i, j, k) for (int i = j; i >= k; i--)

const long long INF = 1e18;
const long long MAX = 1e5 + 10;

int main()
{
    fastio;
    int t = 1;  cin>>t;
    while (t--)
    {
      int n ; cin>>n; 
      int a[n+1]; FOR(i,1,n+1) cin>>a[i];
      int dp[n+1][n+1];
      int ans = 0;
      FOR(i,1,n+1) dp[0][i] = 0,dp[i][0] = 0,dp[1][i] = a[i],ans= max(ans,a[i]);
      FOR(i,1,n) dp[2][i] = max(a[i],a[i+1]),ans= max(ans,dp[2][i]);
      FOR(l,3,n+1){
          FOR(i,1,n+1){
             int j = i+l-1;
             if(j>n) continue;
             dp[l][i] =  max(min(dp[l-2][i+2],dp[l-2][i+1]) + a[i], min(dp[l-2][i], dp[l-2][i+1]) + a[j]); 
             ans = max(ans,dp[l][i]);
            }
      }
      cout<<ans<<"\n";
    }
}

