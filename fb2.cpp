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
    int t,T; cin>>t;
    T=1;
    while(t--){
        string s;cin>>s;
        int k; cin>>k;
        vector<int>adj[30];
        FOR(i,0,k){ 
            string p; cin>>p;
            adj[p[0]-'A'].push_back(p[1]-'A');
        }
        LL dis[30][30];
        FOR(i,0,30) FOR(j,0,30) dis[i][j]=INF;
        for(int ch = 0; ch<=26; ch++){
             vector<int>vis(30,0);
             queue<int>q; dis[ch][ch]=0;
             q.push(ch);vis[ch]=1;
             while(!q.empty()){
                 int u = q.front(); q.pop();
                 for(int i=0;i<adj[u].size();i++){
                     int v = adj[u][i];
                     if(vis[v]) continue;
                     dis[ch][v] = min(dis[ch][v], dis[ch][u]+1);
                     q.push(v);
                     vis[v]=1;
                 }
             }
        }

        LL ans = INF;
        for(char ch = 'A'; ch<='Z'; ch++){
            LL res = 0;
            FOR(i,0,s.size()){
                int st  = s[i]-'A';
                int en  = ch-'A';
                if(dis[st][en]==INF) {
                    res=-1; break;
                }
                res+=dis[st][en];
            }
            if(res!=-1) 
            ans = min(ans,res);
        }
        if(ans==INF) ans = -1;
        cout<<"Case #"<<T++<<": "<<ans<<"\n";
    }
}