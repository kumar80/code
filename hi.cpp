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

LL* f(int n, int q , LL *r, LL *qu ){
    map<LL,LL> m;
    for(int i=0;i<n;i++){
        auto it = m.find(r[i]);
        if(it != m.end())
            it->second++;
        else m.insert({r[i],1});
    }
    LL ans[q];
    for(int i=0;i<q;i++){
        auto it = m.find(qu[i]);
        if(it == m.begin()){
            
        }
    }   
}
int main(){
    fastio;
    int n; cin>>n;
}