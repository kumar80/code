#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for (auto i = j; i < k; i++)

int main() {
    int n,k; cin>>n>>k;
    map<int,int>mp;
    vector<int>mx(n+1,0);
    vector<int>adj[n+1];
    vector<int>vis(n+1,0);
    queue<int>q;
    FOR(i,0,k) {
        int p; cin>>p;
        mp[p]=1;
    }
    FOR(i,0,n-1){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(mp[n]) mx[n]=1;
    q.push(n);
    while(!q.empty()){
        int u = q.front();
        q.pop(); vis[u]=1;
        FOR(i,0,adj[u].size()) {
            int v= adj[u][i];
            if(!vis[v]) {
                if(mp[v])
                mx[v] = 1 + mx[u];
                else mx[v]  = mx[u];
                q.push(v);
            }
        }
    }
    int ans = 0;
    FOR(i,0,n+1) ans = max(ans,mx[i]);
    cout<<ans;
}