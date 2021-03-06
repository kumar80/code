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
#define all(v) v.begin(),v.end()
#define pr(v) pair<v,v>
#define pb push_back
#define FOR(i, j, k) for (auto i=j ; i<k ; i++)
#define ROF(i, j, k) for (auto i=j ; i>=k ; i--) 
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false); debug("%s time : %.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))

const long long INF = 1e18;
const long long MAX = 2e5+10;
vector<int>adj[MAX];

void dfs(int u, int p,vector<int>&nodes){
    nodes[u]=1;
    for(auto v : adj[u]){
      if(p!=v) {
        dfs(v,u,nodes);
       nodes[u]+=nodes[v];
      }
    }
}
void centroid(int u, int p , vector<int>&nodes, int &gc ,int t,vector<int>&lc){
      int lo=t-nodes[u];
      for(auto v : adj[u]) {
        if(p!=v){
            centroid(v,u,nodes,gc,t,lc);
            lo=max(lo,nodes[v]);
        }
      }
      lc[u]=lo;
      gc = min(gc,lo);
}
void dfs2(int u,int p , int &k, int q,int &p1){
    k = u; p1=p;
    for(auto v : adj[u]) {
         if(v!=p && q!=v) 
            dfs2(v,u,k,q,p1);
    }
}
int main(){
    fastio;
    int t=1; cin>>t;
    while(t--){
        int n; cin>>n; 
        FOR(i,0,n-1) {
            int x,y; cin>>x>>y;
            adj[x].push_back(y); adj[y].push_back(x);
        }
      vector<int>nodes(n+1);
      dfs(1,-1,nodes);
      int c=INT_MAX;
      vector<int>lc(n+1);
      vector<int>cs;
      centroid(1,-1,nodes,c,n,lc);
      FOR(i,0,n+1) if(c==lc[i]) cs.push_back(i);
    //  cout<<cs[0]<<" "<<cs[1]<<" "<<c<<" ,";
      if(cs.size()==1) {
        cout<<1<<" "<<adj[1][0]<<"\n";
        cout<<1<<" "<<adj[1][0]<<"\n";
      }else {
          int k =0,k2=0,p=0; 
          dfs2(cs[1],-1,k,cs[0],p); //dfs2(cs[0],-1,k2,cs[1],c);
          cout<<p<<" "<<k<<"\n";
          cout<<k<<" "<<cs[0]<<"\n";
      }
      FOR(i,0,n+1) adj[i].clear(); 
    }

}
