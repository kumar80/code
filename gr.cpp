#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define ll int
#define ii pair <ll, ll>
#define mp make_pair

using namespace std;

vector <bool> vis;
vector <vector <int> > g;
ll s;

int dfs(int u){
    int r = 1;
    vis[u] = true;
    for(int i = 0 ; i < g[u].size() ; i++){
        int v = g[u][i];
        if(!vis[v]) r += dfs(v);
    }
    return r;
}

bool cmp(ii a, ii b){
    if(a.first == b.first){
        return (a.second == s);
    }
    return (a.first > b.first);
}

int main()
{	
    int t; cin>>t;
    while(t--){

    ll n, m, a, b;
    cin >> n >> m >> s;
    s--;
    for(int i = 0;i<g.size();i++) g[i].clear(); 
    g.assign(n, vector <int>(0));
    while(m--){
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
    }
    vector <ii> v;
    for(int i = 0 ; i < g.size() ; i++){
        vis.assign(n, false);
        v.push_back( mp( dfs(i), i) );
    }
    sort(v.begin(), v.end(), cmp);
    vis.assign(n, false);
    int r = 0;
    for(int i = 0 ; i < v.size() ; i++){
        int u = v[i].second;
        if(vis[u]) continue;

        if(u != s) r++;
        int basura = dfs(u);
    }
    cout << r<<"\n";
    }
    return 0;
}




