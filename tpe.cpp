#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for (auto i=j ; i<k ; i++)
#define ROF(i, j, k) for (auto i=j ; i>=k ; i--) 

int main() {
    int n,m; cin>>n>>m;
    vector<int>adj[n+1];
    FOR(i,0,n-1) {
        int u,v; cin>>u>>v; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>vis(n+1,0);
    vector<int>q;
    q.push_back(0);
    int it=0,t=n-1;
    while(q.size()!=n){        
        vector<int>temp = q;       
        FOR(i,0,temp.size()) {
            int u = temp[i];int ctr = m;
            vector<int>tt = adj[u];
            ROF(j,tt.size()-1,0){
                    ctr--;
                    q.push_back(adj[u][j]);
                    adj[u].pop_back();
                    if(ctr==0) break;
            }
        }
        it++;
    }
    cout<<it;
}