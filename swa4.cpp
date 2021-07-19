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
vector<int>adj[MAX];
vector<int>d(MAX);

int ans = -1,x,y;
bool dfs(int u, int p){
    int cnt = 0;
    d[u] = 1;
    for(auto v:adj[u]){
        if(p!=v) {
            cnt+=dfs(v,u);
            d[u]+=d[v];
        }
    }
    cnt = (u==x || u==y)?cnt+1:cnt;
    if(cnt==2 && ans == -1) ans = u;
    return cnt;
}
int main(){
    fastio;
    int t=1;// cin>>t; 
    while(t--){
        int v,e; cin>>v>>e>>x>>y;
        FOR(i,0,MAX) adj[i].clear(),d[i]=0;
        ans = -1;
        FOR(i,0,e){
            int u,v; cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1,0);
        cout<<ans<<" "<<d[ans]<<"\n";
    }
}