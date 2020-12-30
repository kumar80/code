#include<bits/stdc++.h>
using namespace std;

#define LL long long 
#define mod 1000000007 
#define FOR(i, j, k) for (auto i=j ; i<k ; i++)

int main() {
    int t; cin>>t;
    while(t--){
        int n,k,x; cin>>n>>k>>x;
        if(x>k) k++;
        LL dp[n+1][k+1];
        FOR(i,0,n+1) dp[i][0]=0;
        FOR(i,0,k+1) dp[0][i]=0;
        FOR(i,0,k+1) dp[1][i] = i;
        FOR(i,0,k+1) dp[2][i] = k + (k-1)*(k-1);
        FOR(i,1,k+1){
            FOR(j,3,n+1) {
                 LL v =  (((i-1)*dp[j-1][i])%mod+mod)%mod;
                 dp[j][i] = ((v + dp[j-2][i])%mod+mod)%mod;
            }
        }
        cout<<dp[n][k]<<"\n";
     } 

}