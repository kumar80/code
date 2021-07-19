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
struct sq{
    LL x,y,l;
};
struct pt{
    LL x,y;
};

int main(){
    fastio;
    int t=1; //cin>>t;
    while(t--){
        int n; cin>>n;
        vector<sq>v(n);
        FOR(i,0,n){
            cin>>v[i].x>>v[i].y>>v[i].l;
        }
        LL ans =1;
        int lx=v[0].x,ly=v[0].y,ux=v[0].x+v[0].l,uy=v[0].y+v[0].l;
        vector<vector<int>> c = {{0,0},{0,1},{1,1},{1,0}};
        FOR(i,1,n){
            vector<sq>p;
            FOR(j,0,4){
                int x=v[i].x + c[j][0]*v[i].l ,y=v[i].y + c[j][1]*v[i].l;
                if(x >=lx && x<=ux && y>=ly && y<=uy ){
                    p.push_back({x,y,j});
                }
            }
            if(p.size() == 4){
                lx = p[0].x; ly = p[0].y;
                ux = p[2].x; uy = p[2].y;
            }
            if(p.size() == 2){
                if(p[0].l==0 && p[1].l==1){
                    lx = p[0].x; ly = p[0].y;
                    uy = p[1].y;
                }
                if(p[0].l==1 && p[1].l==2){
                    lx = p[0].x;
                    ux = p[1].x; uy = p[1].y;
                }
                if(p[0].l==2 && p[1].l==3){
                    ly = p[1].y;
                    ux = p[0].x; uy = p[0].y;
                }
                if(p[0].l==0 && p[1].l==3){
                    lx = p[0].x; ly = p[0].y;
                    ux = p[1].x;
                }
            }
            if(p.size()==1){
                if(p[0].l==0){
                    lx = p[0].x; ly = p[0].y;
                }
                if(p[0].l==1){
                    lx = p[0].x;
                    uy = p[0].y;
                }
                if(p[0].l==2){
                    ux = p[0].x; uy = p[0].y;
                }
                if(p[0].l==3){
                    ly = p[0].y;
                    ux = p[0].x;
                }
            }
            if(!p.size()) {
                ans = 0;
                break;
            }
        }
        int l = abs(lx-ux),b=abs(ly-uy);
        cout<<l*b*ans<<"\n";
    }
}