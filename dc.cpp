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
bool pos(int i,int j,int n, int m) {
    if(i<0 || i>=n || j<0 || j>=m) return 0;
    return 1;
}
int main(){
    fastio;
    int t=1; cin>>t;
    while(t--){
        int n,m; cin>>n>>m; int ans=0;
        vector<vector<int>>vec(n,vector<int>(m));
        FOR(i,0,n) FOR(j,0,m) cin>>vec[i][j];
        queue<pair<int,int>>f,b;
        f.push({0,0,}); b.push({n-1,m-1}); 
        vector<vector<int>>vis(n+10,vector<int>(m+10,0));vis[0][0]=vis[n-1][m-1]=1;
        while(!f.empty() && !b.empty()){
             queue<pair<int,int>>_f,_b;
             int f0=0,f1=0,b0=0,b1=0;
             while(!f.empty()) {
                 auto u = f.front(); f.pop();
                 if(vec[u.first][u.second]) f1++; else f0++;
                 if(pos(u.first+1,u.second,n,m) && !vis[u.first+1][u.second]) _f.push({u.first+1,u.second}),vis[u.first+1][u.second]=1;  
                 if(pos(u.first,u.second+1,n,m) && !vis[u.first][u.second+1]) _f.push({u.first,u.second+1}),vis[u.first][u.second+1]=1;  
             }   
              while(!b.empty()) {
                 auto u = b.front(); b.pop();
                 if(vec[u.first][u.second]) b1++; else b0++;
                 if(pos(u.first-1,u.second,n,m) && !vis[u.first-1][u.second]) _b.push({u.first-1,u.second}),vis[u.first-1][u.second]=1;  
                 if(pos(u.first,u.second-1,n,m) && !vis[u.first][u.second-1]) _b.push({u.first,u.second-1}),vis[u.first][u.second-1]=1;  
             }  
            ans += min(f0+b0,f1+b1);
             f=_f;b=_b;    //   cout<<f0<<" "<<f1<<", "<<b0<<" "<<b1<<" ;";
        }
        // int lo = 0 , hi = m-1;
        // while(lo<=hi ){
        //     int i=0,j=lo,k=n-1,l=hi;  
        //     int v0=0,v1=0,b0=0,b1=0;
        //   //  if(m&1 && lo==(m+1)/2) break;
        //     while(i<n && j>=0 && k>=0 && l<m) {
        //         if(v[i][j]) v1++; else v0++;
        //         if(v[k][l]) b1++; else b0++;
        //         i++,j--; k--; l++;
        //     }lo++,hi--;
        //     //cout<<v1<<" "<<b1<<", ";
        //     ans += min(b0+v0,v1+b1);
        // }
        // hi=n-1-lo; cout<<lo<<" "; int sp=lo;
        //    while(hi>){
        //     int i=lo,j=0,l=n-1,k=hi;  
        //     int v0=0,v1=0,b0=0,b1=0; 
        //   //  if(m&1 && lo==(m+1)/2) break;
        //     while(i>=0 && j<m && k<n && l>=0) {
        //         if(v[i][j]) v1++; else v0++;
        //         if(v[k][l]) b1++; else b0++;
        //         i--,j++; k++; l--;
        //     }lo++,hi--;
        //     //cout<<v1<<" "<<b1<<", ";
        //     ans += min(b0+v0,v1+b1);
        // }
        // vector<pair<int,int>>f;
        // FOR(c,0,m){
        //     int r = 0,te=c;; int cnt=0,pp=0;
        //     while(c>=0 && r<n) {
        //         if(v[r][c]) cnt++;
        //         r++; c--;  pp++;
        //     }c=te;
        //     f.push_back({pp,cnt});
        // }
        // for(auto i : f) cout<<i.first<<" "<<i.second<<" ,";
        // int i=0,j=f.size()-1;
        // while(i<j){
        //     ans += min(f[i].first-f[i].second  + f[j].first - f[j].second, f[i].second + f[j].second );
        //     i++; j--;
        // }
        cout<<ans<<"\n";
    }
}
