#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
#define LL long long
#define mod 998244353
#define FOR(i, j, k) for (int i = j; i < k; i++)
#define ROF(i, j, k) for (int i = j; i >= k; i--)

const long long INF = 1e18;
const long long MAX = 1e5 + 10;
struct pt{
    int i,j;
};
int n,m;
int a[10][10];
long long vis[10][10], dp[10][10][50];
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

bool check(int i, int j){
    return (i>=0 && j>=0 && i<n && j<n && a[i][j]!=9 && !vis[i][j]);
}

int dfs(int i, int j, int u, int v, int l){
                  cout<<i<<" "<<j<<" "<<l<<" "<<dp[i][j][l]<<" *\n";
  if(l<0 || (i==u && j==v && l!=0)) return 0;
    vis[i][j] = 1;
    if(dp[i][j][l]) return dp[i][j][l];
    for(int k=0;k<4;k++){
        int x = i+dx[k],y=j+dy[k];
        if(check(x,y)){
            dp[i][j][l]+=dfs(x,y,u,v,l-1);
        }
    }
    vis[i][j] = 0;

    return dp[i][j][l];
}
int main()
{
    fastio;
    int t = 1; // cin>>t;
    while (t--)
    {
        cin>>n>>m;
        vector<pt>v(10);
        FOR(i,0,n) FOR(j,0,n) {
            cin>>a[i][j];
            v[a[i][j]] = pt({i,j});
        }
        int ans = 1;
        FOR(j,3,m){
            bool ok = false;
            FOR(i,1,50){
                FOR(p,0,10) FOR(q,0,10) vis[i][j]=0;
                FOR(p,0,10) FOR(q,0,10) FOR(r,0,50) dp[p][q][r]=0;
                dp[v[j].i][v[j].j][0] = 1;
                int res =  dfs(v[j+1].i,v[j+1].j,v[j].i,v[j].j,i);
                cout<<res<<" ---- ";
                if(res > 0) {
                    ans*=res;
                    ok=true;
                    break;
                }
            }
            if(!ok) {
                ans = 0;
                break;
            }
        }
        cout<<ans<<"\n";
    }
}

