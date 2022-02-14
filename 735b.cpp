#include<bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define LL long long 
#define mod 1000000007 
#define all(v) v.begin(),v.end()
#define pr(v) pair<v,v>
#define pb push_back
#define FOR(i, j, k) for (auto i=j ; i<k ; i++)
#define ROF(i, j, k) for (auto i=j ; i>=k ; i--) 
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false); debug("%s time : %.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))

const long long INF = 1e18;
const long long MAX = 2e5+10;

int main(){
    fastio;
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        LL ans = INT_MIN;
        LL a[n+1]; FOR(i,1,n+1) cin>>a[i];
        ROF(i,n,max(1,n-250))
            ROF(j,i-1,max(1,n-250)){
                ans = max(ans,i*j - k*(a[i] | a[j]) );
            }
        cout<<ans<<"\n";
    }
}