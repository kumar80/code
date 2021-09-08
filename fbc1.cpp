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

LL dfs(vector<int>adj[], vector<int>&vis, vector<LL>&g,
             int u, LL &ans, LL sum,int k){
    vis[u]=1;
    vector<LL>res;
    for(auto v : adj[u]){
        if(vis[v]) continue;
        LL gg = dfs(adj,vis,g,v,ans,sum+g[v],k);
        res.push_back(gg);
        
    }
    sort(res.begin(),res.end(),greater<int>());
    if(u == 1) {
        LL temp = 0;
        FOR(i,0,min(k+1,(int)res.size()))
             temp+=res[i];            
        ans = max(ans, sum  + temp);
    }
    LL a = 0;
    if(res.size()) a = res[0];
    return  g[u] +  a;
}

int main(){
    fastio;
    int t,T; cin>>t;
    T=1;
    while(t--){
        int n,k; cin>>n>>k;
        vector<LL>g(n+1);
        FOR(i,1,n+1) cin>>g[i];
        vector<int>adj[n+1];
        FOR(i,0,n-1){
            int x,y; cin>>x>>y; 
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<int>vis(n+1,0);
        LL ans = -INF;
        dfs(adj,vis,g,1,ans,g[1],k);
        cout<<"Case #"<<T++<<": "<<ans<<"\n";
    }
}