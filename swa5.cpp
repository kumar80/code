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
struct pt{
    int x,y;
};
int ox,oy,hx,hy,res=INT_MAX;

int f(vector<bool>vis,int p, int sum, vector<pt>&v){
    bool ok = true;
    FOR(i,0,vis.size()) 
        ok = ok && vis[i];
    if(ok)
        return sum + abs(v[p].x-hx) + abs(v[p].y-hy);
    int ans = INT_MAX;
    FOR(i,0,v.size()){
        if(!vis[i]){
            vector<bool>t = vis;    t[i]=1;
            ans = min(ans, abs(v[p].x - v[i].x) + abs(v[p].y-v[i].y)+f(t,i,0,v));
        }
    }
    return ans;
}
void per(vector<pt>v, int l , int r){
    if(l==r){
        int ans = abs(ox-v[0].x) + abs(oy-v[0].y) + abs(hx - v[v.size()-1].x) + abs(hy-v[v.size()-1].y);
        FOR(i,0,v.size()-1){
            ans += abs(v[i].x - v[i+1].x) + abs(v[i].y - v[i+1].y);
            res = min(res,ans);
        }
        return ;
    }
    FOR(i,l,r+1){
        swap(v[l],v[i]);
        per(v,l+1,r);
        swap(v[l],v[i]);
    }

}
int main(){
    fastio;
    int t=1;// cin>>t; 
    while(t--){
        int n; cin>>n;
        vector<pt>v(n);
        vector<pt>r(2);
        cin>>ox>>oy>>hx>>hy;
        FOR(i,0,n) cin>>v[i].x>>v[i].y;
        per(v,0,v.size()-1);
        cout<<res<<"\n";
    }
}