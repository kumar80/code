#include<bits/stdc++.h> 
using namespace std; 
#define FOR(i, j, k) for (auto i=j ; i<k ; i++)

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
struct Point{
    int x,y;
};
bool check(int i, int j, int n, int m){
    if(i<0 || j<0 || i>=n || j>=m) 
        return false;
    return true;
}
int main(){
    int r,c,gd=0,a,b; cin>>r>>c;
    int m[r][c],vis[r][c];
    FOR(i,0,r) 
        FOR(j,0,c) {
            cin>>m[i][j],vis[r][c]=0;
            if(m[i][j]==2) gd++;
        }
    cin>>a>>b;
    queue<pair<Point,Point>>q;
    q.push({{0,0},{0,gd}});
    int mx = INT_MAX;
    while(!q.empty()){

        auto pt  = q.front();
        Point p = pt.first; 
        Point _q = pt.second;
        q.pop(); vis[p.x][p.y] = 1;

        if(p.x==a && p.y == b && 0 == _q.y)
               mx = min(mx,_q.x);

        FOR(i,0,4) {
            int x  = p.x + dx[i];
            int y =  p.y + dy[i];
            if(check(x,y,r,c)  && vis[x][y]==0  && m[x][y]!=1){
                int g = 0;
                if(m[x][y]==2) g=1;
                q.push( {{x,y},{ _q.x+1, _q.y-g}} );
            }
        }
    }
    if(INT_MAX!=mx) {
        cout<<mx;
    }
    else cout<<-1;
}