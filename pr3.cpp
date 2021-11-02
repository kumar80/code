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
int n,m,c,k;
struct pt{
    int x,y;
};

bool ok(int i, int j, int n, int m){
    return (i>=0 && j>=0 && i<n && j<m);
}

int getIndex(int i, int j ,int n, int m){
    return i*m + j;
}

pt get2Index(int u, int n, int m){
    int y=u%m,x=(u-y)/m;
    return pt({x,y});
}

int dj(vector<vector<LL>> a, vector<vector<LL>> s, LL si, LL sj, LL c){
    LL n = a.size(),m=a[0].size();
    vector<vector<LL>>dis(n,vector<LL>(m,INT_MAX));
    dis[0][0] = 0;     
    set<pair<LL,LL>>st;
    st.insert({0,0});
    FOR(i,0,n)
        FOR(j,0,m)  
        if(s[i][j]==1) {
            int v = getIndex(i,j,n,m);
            dis[i][j] = c+a[i][j];
            st.insert({dis[i][j],v}); 
        }
        
    LL dx[] = {-1,0,1,0};
    LL dy[] = {0,-1,0,1};
    while(!st.empty()){
        auto p = *st.begin();
        st.erase(st.begin());
        pt u = get2Index(p.second,n,m);
  //      cout<<"\n"<<p.second<<" # ";
        for(int i=0;i<4;i++){
            int x=u.x+dx[i],y=u.y+dy[i];
            if(!ok(x,y,n,m)) continue;
            LL d = dis[u.x][u,y] + a[x][y];
            int v = getIndex(x,y,n,m);
//            cout<<x<<" "<<y<<" "<<v<<" "<<dis[u.x][u.y]<<" * ";

            if(dis[x][y] > d){
                if(dis[x][y] != INT_MAX)
                    st.erase(st.find({dis[x][y],v}));
                dis[x][y] = d;
                st.insert({d,v});
            }
        }
    }

    return dis[n-1][m-1];
}

int main()
{
    fastio;
    int t = 1;  cin>>t;
    while (t--)
    {   cin>>n>>m>>c>>k;
        vector<vector<LL>> a(n,vector<LL>(m)),s(n,vector<LL>(m,0));
        FOR(i,0,n) FOR(j,0,m) cin>>a[i][j];
        FOR(i,0,k){
            int u,v; cin>>u>>v;
            s[u][v] = 1;
        }
        cout<<dj(a,s,0,0,c)<<"\n";
    }
}