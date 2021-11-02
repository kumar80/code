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

vector<int>adj[1000*1000];
vector<int>p(1000*1000,-1);
void dfs(int u, int pr){
    p[u] = pr;
    for(auto v : adj[u])
        if(p[v]==-1 && v!=1)
            dfs(v,pr);
}
int main()
{
    fastio;
    int n,q; cin>>n>>q;
    FOR(i,0,n-1){
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(auto v : adj[1]){
        dfs(v,v);
        p[v] = -1;
    }
    while(q--){
        int a, b; cin>>a>>b;
        if(p[a]==p[b] && p[a]!=-1) cout<<2<<"\n";
        else cout<<1<<"\n";
    }
}