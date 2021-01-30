#include<bits/stdc++.h> 
using namespace std; 
#define FOR(i, j, k) for (int i=j ; i<k ; i++)
bool prime[1000*1000];
int sub[1000*1000];
vector<int>adj[1000*100+10];
void S(long long  n){

    memset(prime, true, sizeof(prime));
 
    for (long long p = 2; p * p <= n; p++)
    {

        if (prime[p] == true) 
        {
            for (long long i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
}
int dfs(int u,int parent, vector<int>&val){

    for(auto v : adj[u]) {
        if(v!=parent) 
          sub[u]+=dfs(v,u,val);
    }

    return sub[u]  =  sub[u]  +  prime[val[u]];
}

vector<int> fg(int n, vector<int>f, vector<int>s, vector<int>val, vector<int>qq){
    int m = f.size();
    int q = qq.size();
    S(1000*1000);
    memset(sub, 0, sizeof(sub));
    FOR(i,0,m) {
        adj[f[i]].push_back(s[i]);
        adj[s[i]].push_back(f[i]);         
    }
    dfs(1,0,val);
    vector<int> ans;
    FOR(i,0,q) {
        ans.push_back(sub[qq[i]]);
    }
    return ans;
}
int main() {

    int n,m;    cin>>n>>m;
    vector<int> f(m),s(m);
    FOR(i,0,m) cin>>f[i];
    cin>>m;
    FOR(i,0,m) cin>>s[i];
    cin>>n;
    vector<int>v(n+9);
    FOR(i,1,n+1) cin>>v[i]; 
    int q; cin>>q;
    vector<int> t(q);
    FOR(i,0,q) cin>>t[i];

    vector<int>ans = fg(n,f,s,v,t);
    FOR(i,0,q) cout<<ans[i] <<"\n";

}