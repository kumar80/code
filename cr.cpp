/*              |\ | |  ||\ \ /(_~     |~)|_~|\/||_~|\/||~)|_~|~)
                |~\|_|/\||~\ | ,_)     |~\|__|  ||__|  ||_)|__|~\

                   \ //~\| |    |\ |~)|_~    | ||\ ||/~\| ||_~
                    | \_/\_/    |~\|~\|__    \_/| \||\_X\_/|__
                (J U S T   L I K E   E V E R Y O N E   E L S E !)

                             __ ,..---.._
                            +''''`--''-..`--..__
                           .\ _,/:i--._`:-:+._`.``-._
                          /`.._,,' \   `-.``--:.b....=.
                         |`..__,,..`.    '`.__::i--.-::_
                         )- .....--i'\..      --+`'''-'
                       ,' .'.._,.-'|._-b\
                      /,'<'    V   `oi| \             _.
                     |/ -|,--.." ,'-. ||\..      _.,;:'_<'
                     ''/ |  . ' |\||'\    /-'_/' `.
                    |,','|    , .    .-.|:.`.  + .,:..  |
                 ._,:'/ /-\   '^'   -Y"\ |.| || /,+8d| |
                .|/,'| |/':: ':=:' ,'|  | | \|| "+)='  |
                |+,';' /|_/ \     _/ \b':.\  \'| .||   ,'
                ,,:-i''_i' | ``-.Y',. ,|`: | \;- | |_,'
          __   |'| |i:'._ ,'     ,' ,; | |-)-'  __--:b__
         .P|   | |/,'|\  - ._   /  /   _,Y-   ,:/'  `.  `'".._
        ,'|| -','' | ._i._   `':| ,..,'     ,Y;'      \       `- ._
       |||||,..    | \ '-.._ _,' /       _,b-'         `.         '-.
       ||||P..i,  .| '....,-' _,'''''-'''               '    _,..    `\
       +'`   <'/  |`-.....---'                       ._         ,._
        |      |                                    ,'``,:-''''/,--`.
       Y|.b_,,:  |              ||                 ,;,Y'      /     |.
     ,' /'----' .'|   ..       |  |         '"   .`Y'     .,-b_....;;,.
    |+|,'     | | \.,  '      ,'  `:.  _     ,/__`     _=:  _,'``-
   / +,'      | /\_........:.'      '"----:::::'Y  .'.|   |||
   |' '      .'/- \                          /'|| || |   |||
   |||      /|     \L                        /'|| ||/ |   |||
   `.|    ,'/       .|                      / ,'||/o;/    |||
     `..._,,         |                      |/|   '       |||
       ``-'          |                      |,            |||
                     |          ,.          |             |||
  ,=--------....     |          ""          |             |||
,/,'.            i=..+._             ,..    '..;---:::''- | |
'/|           __....b `-''`---....../.,Y'''''j:.,.._      | `._
.'      _.Y.-'       `..       ii:,'--------' |     :-+. .| | b\
|     .=_,.---'''''--...:..--:'  /         _..-----..:=   | | '|\
|    '-''`'---                  ---'_,,,--''           `,.. |  | \.
 \  .                      ,' _,--''        :dg:      _,/ |||   |  \
`::b\`                 _,-i,-'                 ,..---'    ,|:|  | _|
`'--.:-._      ____,,,;.,'' `--._      ''''''''           |'|' .'  '
     ``'--....Y''-'              `''--..._..____._____...,' |  'o-'
                                             `''''`'''i==_+=_=i__
                                                     ||'''- '    `.
                                                      `-.......-''
*/                              
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
bool  pos; 
void f(vector<string>&v, int i, int j,int n,int m){
    if(i<0 || j>=m || i>=n || j<0) return;
    if(v[i][j]=='G') pos=false;
    if(v[i][j]=='.') v[i][j]='#';
}
void dfs(int i, int j , vector<vector<int>>&vis,vector<string>&v ,int n, int m,int &g){
    if(i<0 || j>=m || i>=n || j<0) return;
    if(vis[i][j]  || v[i][j]=='#') return;
    vis[i][j]=1; if(v[i][j]=='G') g++;
    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};
    FOR(k,0,4) 
        dfs(i+dx[k],j+dy[k],vis,v,n,m,g);
}
int main(){
    fastio;
    int t=1; cin>>t;
    while(t--){
        int n,m; cin>>n>>m; pos = true;
        vector<string>v(n);
        FOR(i,0,n) cin>>v[i]; int cnt = 0;
        FOR(i,0,n) {
            FOR(j,0,m){
                if(v[i][j]=='B') {
                    f(v,i-1,j,n,m);
                    f(v,i+1,j,n,m);
                    f(v,i,j-1,n,m);
                    f(v,i,j+1,n,m);
                } if(v[i][j]=='G') cnt++;
            }
        } 
        if(!pos) {cout<<"No\n"; continue;}
        vector<vector<int>>vis(n+1,vector<int>(m+1,0));
        FOR(i,0,n) {
            FOR(j,0,m){
                if(!vis[i][j] && v[i][j]=='G') {
                        int g=0;
                        dfs(i,j,vis,v,n,m,g); 
                        if(vis[n-1][m-1]==1)cnt-=g;
                    } 
                vis[n-1][m-1]=0;
            }
        }
     //   FOR(i,0,n) FOR(j,0,m )cout<<vis[i][j]<<" ";
        if(cnt==0) cout<<"Yes\n";
        else cout<<"No\n";
    }
}
