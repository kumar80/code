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
    int t=1;// cin>>t;
    while(t--){
        set<int> b[10000],l[10000];
        int n,j=1,k=0,len; cin>>n;
        string s; cin>>s; len = s.size();
        FOR(i,0,len){
            if(s[i]==',') {
                b[j].insert(k),l[k].insert(j); j++;k=0;
            }else if(s[i]=='&') {
                b[j].insert(k); l[k].insert(j);k=0;
            }else k=k*10+s[i]-'0';
        }
        b[j].insert(k);l[k].insert(j);
        int ans = 0;
        j=1; cin>>n; k =0;
        cin>>s; len = s.size();
        FOR(i,0,len){
            if(s[i]==',') {
                 b[j].insert(k);l[j].insert(k); j++;k=0;
            }else if(s[i]=='&') {
                b[j].insert(k); l[j].insert(k);k=0;
            }else k=k*10+s[i]-'0';
        }
        l[j].insert(k); b[j].insert(k);
        FOR(i,0,10000) ans = max({ans,(int)b[i].size(),(int)l[i].size()}); 
        cout<<ans;
    }

}