#include<bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define LL long long 
#define mod 1000000007 
#define FOR(i, j, k) for (int i=j ; i<k ; i++)
#define ROF(i, j, k) for (int i=j ; i>=k ; i--) 
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false); debug("%s time : %.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))

const long long INF = 1e18;
const long long MAX = 1e5+10;
int bs(vector<int>v,int x){
    int l =0,r=v.size()-1,j=-1;
    while (l<=r)
    {
        int m = (l+r)/2;
        if(v[m]>x) {
            j=m;
            r=m-1;
        }else l=m+1;
    }
    return j;
}
int main(){
    fastio;
    int t=1; //cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n];
        FOR(i,0,n) cin>>a[i];
        vector<int>dp(n,INT_MAX);
        int l = 1;
        dp[0] = a[0];
        FOR(i,1,n){
            int j = bs(dp,a[i]);
            if(dp[j]==INT_MAX) dp[l++] = a[i];
            else dp[j] = a[i];
        }
        for(auto i : dp) cout<<i<<" ";
        cout<<"\n";
        cout<<l<<"\n";
    }
}
