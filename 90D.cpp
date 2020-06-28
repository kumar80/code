#include<bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define LL long long 
#define mod 998244353 
#define FOR(i, j, k) for (int i=j ; i<k ; i++)
#define ROF(i, j, k) for (int i=j ; i>=k ; i--) 

LL maxEvenLenSum(int arr[], int n) 
{ 

    if (n < 2) 
        return 0; 

    LL dp[n] = { 0 }; 

    dp[n - 1] = 0; 
    dp[n - 2] = arr[n - 2] + arr[n - 1]; 
  
    for (int i = n - 3; i >= 0; i--) { 

        dp[i] = arr[i] + arr[i + 1]; 
        if (dp[i + 2] > 0) 
            dp[i] += dp[i + 2]; 
    } 

    LL maxSum = *max_element(dp, dp + n); 
    return maxSum; 
} 
int main(){
    fastio;
    int t; cin>>t;
    while(t--){
     int n ; cin>>n;LL sum=0;int a[n]; 
     FOR(i,0,n){ cin>>a[i];if(i%2==0) sum+=a[i],a[i]=-a[i];}

        LL max_sum = maxEvenLenSum(a, n); 
        if(max_sum<0) max_sum=0;
        cout<<sum+max_sum<<"\n";
    }
return 0; 
} 
