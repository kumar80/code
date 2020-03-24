#include<bits/stdc++.h>
using namespace std;
vector<int>adj[200000];
vector<bool>vis(200000);
int ch[200000];
int ctr=0;
void dfs(int u,vector<bool>&l){
    vis[u]=true;
    for(auto v : adj[u]){
        if(!vis[v]){
                vector<bool>ll(30,false);
                dfs(v,ll);
                for(int i=0;i<30;i++) 
                    if(ll[i]==true) l[i]=true;
            }        
    }
      if(!l[ch[u]]  ){cout<<ch[u]<<" "<<u<<" "; ctr++;}
        l[ch[u]]= true;
}
int main(){
    int t; cin>>t;
    while(t--){
        for(int i=0;i<200000;i++) {adj[i].clear();vis[i]=false;}
        int n; cin>>n;
        int x,y;string s;cin>>s;
        vector<bool> l(30,false);
        ch[0]=s[0]-'a';
        for(int i=1;i<n;i++){
            cin>>x>>y; x--;y--; adj[x].push_back(y);adj[y].push_back(x);
            ch[i]=s[i]-'a';
        }
        dfs(0,l);
        cout<<ctr<<"\n";
        ctr=0;
    }
}