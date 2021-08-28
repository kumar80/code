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
struct pt{
    int x,y;
};
int main(){
    fastio;
    int t,T; cin>>t;
    T=1;
    while(t--){
        int n;cin>>n;
        vector<string>v(n);
        FOR(i,0,n) cin>>v[i];
        int res = INT_MAX;
        FOR(i,0,n){
            int cnt = 0;
            FOR(j,0,n){
                if(v[i][j]=='X') cnt++;
                if(v[i][j]=='O'){
                    cnt=-1; break;
                }
            }
            if(cnt!=-1){
                res = min(n-cnt,res);
            }
            cnt = 0;
            FOR(j,0,n){
                if(v[j][i]=='X') cnt++;
                if(v[j][i]=='O'){
                    cnt=-1; break;
                }
            }
            if(cnt!=-1){
                res = min(n-cnt,res);
            }
        }
        int ans = 0;
        FOR(i,0,n){
            int cnt = 0;
            vector<pt>p;
            FOR(j,0,n){
                if(v[i][j]=='X') cnt++;
                else if(v[i][j]=='O'){
                    cnt=-1; break;
                }
                else p.push_back({i,j});
            }
          //  cout<<cnt<<", ";
            if(n-cnt ==  res) ans++;   

            cnt = 0;
            vector<pt>pp;
            FOR(j,0,n){
                if(v[j][i]=='X') cnt++;
                else if(v[j][i]=='O'){
                    cnt=-1; break;
                }
                else pp.push_back({j,i});
            }
          //  cout<<cnt<<" ,";
            if(res==1 && p.size()==pp.size() && p.size()==1 && p[0].x==pp[0].x && p[0].y ==pp[0].y)
                continue;
            if(n-cnt == res )  ans++;            
        }
        cout<<"Case #"<<T++<<": ";
        if(res==INT_MAX) cout<<"Impossible\n";
        else cout<<res<<" "<<ans<<"\n";
    }
}