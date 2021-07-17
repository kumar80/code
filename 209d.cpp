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
#define FOR(i, j, k) for (int i=j ; i<k ; i++)
#define ROF(i, j, k) for (int i=j ; i>=k ; i--) 
 
const long long INF = 1e18;
const long long MAX = 1e5+10;
const LL  mod = 1000*1000*1000 +7; 
vector<int>adj[MAX];
vector<int>d(MAX,0);
vector<int>f(MAX);
vector<int>e;
vector<int>seg;
void dfs(int u, int p){
    d[u] = d[p] + 1;
    f[u] = e.size();
    e.push_back(u);
    for(auto v : adj[u]){
        if(v!=p) dfs(v,u);
        e.push_back(u);
      }    
}
void build(int i, int l , int r){
    if(l==r){
       seg[i] = e[l];
      return;
    }    
    int m = l + (r-l)/2;
    build(2*i,l,m);
    build(2*i+1,m+1,r);
    seg[i] = d[2*i] < d[2*i+1] ? 2*i : 2*i+1;
}

int query(int l, int r, int b, int e, int i){
    if(b>r || e<l) return -1;
    if(b>=l && e <= r) return seg[i];
    int m = (b+e)/2;
    int L = query(l,r,b,m,2*i);
    int R = query(l,r,m+1,e,2*i+1);
    if(L==-1) return R;
    if(R==-1) return L;
    return d[L]<=d[R]?L:R;
}
void dfs1(int u, int p, int c){
  d[u] = c;
  for(auto v : adj[u]){
    if(v!=p) dfs1(v,u,1-c);
  }
}
int main(){
    fastio;
    int t=1;// cin>>t;
    while(t--){
        int n,q; cin>>n>>q;
        FOR(i,1,n){
            int x,y; cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        // dfs(1,0);
        // seg.resize(MAX*100);
        // build(1,0,e.size()-1);
        // FOR(i,0,q){
        //   int x,y; cin>>x>>y;
        //   int lca = query(min(f[x],f[y]),max(f[x],f[y]),0,e.size()-1,1);
        //   int dis = d[x]-d[lca] + d[y]-d[lca] + 1;
        //   if(dis&1) cout<<"Town\n";
        //   else cout<<"Road\n"; 
        // }
             dfs1(1,0,0);
     FOR(i,0,q){
        int x,y; cin>>x>>y;
        if(d[x]==d[y]) cout<<"Town\n";
        else cout<<"Road\n";
      }
    }
}
