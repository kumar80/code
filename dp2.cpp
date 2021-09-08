#include <bits/stdc++.h>
using namespace std;

int main()
{
  //write your code here
  int n; cin>>n;
  long long a[n+1]; 
  for(int i=1;i<=n;i++) cin>>a[i];
  long long dp1[n+1][2],dp2[n+2][2];
  dp1[0][0]  = dp1[0][1]= 0; dp1[1][0]  = 0; dp1[1][1] =  a[1]; 
  dp2[n+1][0] = dp2[n+1][1] = 0; dp2[n][1] = a[n]; dp2[n][0] = 0;
  for(int i=2;i<=n;i++){
    dp1[i][0] = max(dp1[i-1][0],dp1[i-1][1]);
    dp1[i][1] = max(dp1[i-2][0],dp1[i-2][1]) + a[i];
  }
  for(int i=n-1;i>=1;i--){
    dp2[i][0] = max(dp2[i+1][0],dp2[i+1][1]);
    dp2[i][1] = max(dp2[i+2][0],dp2[i+2][1]) + a[i];
  }
  long long ans =  0;
  for(int i=1;i<=n;i++){
    ans = max(ans, dp1[i][0] + dp2[i][0]);
    ans = max(ans, dp1[i][1] + dp2[i+1][0]);
    ans = max(ans, dp1[i-1][0] + dp2[i][1]);
    // cout<<dp1[i][0]<<" "<<dp1[i][1]<<"; ";
    // cout<<dp2[i][0]<<" "<<dp2[i][1]<<"\n";
  }
  cout<<ans<<"\n";
  return 0;
}