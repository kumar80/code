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
    int t=1;// cin>>t;
    while(t--){
      int n; cin>>n; int a[n]; FOR(i,0,n) cin>>a[i];
      int k; cin>>k;
      int mn = -1, ans=0;
      FOR(i,0,n){
          if(mn==-1 && a[i]==0) mn=i;
          if(mn!=-1 && i-mn+1==k) ans++,mn=-1;
      }
      if(mn!=-1)ans++;
      cout<<ans;
    }

}