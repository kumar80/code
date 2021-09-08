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
vector<bool>prime(300,true);
vector<int>pr[100];
vector<int>adj[10*MAX];
int ans = 0;
int res = 0;

vector<int> s(){
    for(int p=2;p*p<=300;p++){
        if(prime[p]) 
        for(int i=p*p;i<=300;i+=p)
            prime[i]=false;
    }
    vector<int>p;
    FOR(i,2,100) if(prime[i]) p.push_back(i);
    return p;
}

void dfs(int u, int p, vector<bool>&vis,vector<bool>&vis_p){
    if(pr[p].size()<adj[u].size()){
        res = -1;
        return ;
    }
    vis[u] = 1;
    for(auto v : adj[u]){
        if(vis[v]) continue;
        
    }
}

int main(){
    fastio;
    int t=1;// cin>>t;
    while(t--){
        int n; cin>>n;
        FOR(i,0,n-1) {
            int x,y; cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<int>p = s();
        FOR(i,0,p.size()){
            FOR(j,i+1,p.size()){
                if(!prime[p[i] + p[j]]){
                    pr[p[i]].push_back(p[j]);
                    pr[p[j]].push_back(p[i]);
                }
            }
        }
        FOR(i,0,p.size()){
            vector<bool>vis_p(100,false);
            vector<bool>vis(100,false);
            dfs(1,p[i],vis,vis_p);
        }
    }
}
