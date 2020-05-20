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
#define mod 998244353 
#define FOR(i, j, k) for (int i=j ; i<k ; i++)
#define ROF(i, j, k) for (int i=j ; i>=k ; i--) 
 
const long long INF = 1e18;
const long long MAX = 1e5+10;

struct op{
  int x,y,z;
};

void dfs(int u, vector<int>adj[],vector<bool>&vis,deque<int>&ans){
  ans.push_back(u);
  vis[u]=1;
  for(auto v :adj[u])
      if(!vis[v])          
        dfs(v,adj,vis,ans);
}
int main(){
    fastio;
    int t=1; cin>>t;
    while(t--){
        int n,k,x; cin>>n>>k;   
        vector<bool> vis(n,false); vector<op>res;     
        vector<int>adj[n],a(n); 
        FOR(i,0,n) {cin>>x;x--; a[i]=x; if(x!=i) adj[x].push_back(i); else vis[i]=1;}
        deque<int>ans,ans2; 
        FOR(i,0,n){ 
          if(!vis[i])
            dfs(i,adj,vis,ans);
          while(ans.size()>2){
            int x = ans.front(); ans.pop_front(); 
            int y = ans.front(); ans.pop_front(); 
            int z = ans.front(); ans.pop_front();  
            a[z]=a[x]; a[x]=x;a[y]=y; k--;
            res.push_back({y+1,x+1,z+1});
           if(z!=a[z])  ans.push_front(z);
          }
          if(ans.size()==2){
            ans2.push_back(ans.front()); ans.pop_front();
            ans2.push_back(ans.front()); ans.pop_front();
          }   
        }
        while(ans2.size()>3){
            int x = ans2.front(); ans2.pop_front(); 
            int y = ans2.front(); ans2.pop_front(); 
            int z = ans2.front(); ans2.pop_front(); 
            int u = ans2.front(); ans2.pop_front(); 
            res.push_back({y+1,x+1,z+1}); res.push_back({z+1,y+1,u+1});
        }
         x = res.size(); 
        if(k<0 || !ans2.empty() ) {cout<<-1<<"\n";continue;}
        cout<<x<<"\n";
        FOR(i,0,res.size())
          cout<<res[i].x<<" "<<res[i].y<<" "<<res[i].z<<"\n";
    }
}
