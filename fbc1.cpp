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
        int n; cin>>n;
        vector<LL>g(n+1);
        FOR(i,1,n+1) cin>>g[i];
        vector<int>adj[n+1];
        FOR(i,0,n-1){
            int x,y; cin>>x>>y; 
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<int>vis(n+1,0);
        queue<int>q;
        LL a=-INF,b=-INF,ans=0;
        q.push(1); vis[1]=1;
        while(!q.empty()){
            int u = q.front(); q.pop();
            int ctr=0;
            FOR(i,0,adj[u].size()){
                int v = adj[u][i];
                if(vis[v]) continue;
                g[v] += g[u];
                vis[v]=1;
                q.push(v);
                ctr++;
            }
            if(ctr==0){
                if(g[u]>a) b=a,a=g[u];
                else if(g[u]>b) b=g[u];
            }
        }
        if(a!=-INF) ans+=a;
        if(b!=-INF) ans+=b-g[1];
        cout<<ans<<"\n"; 
    }
}