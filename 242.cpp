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

  void dfs(int u, vector<int>adj[],vector<bool>&vis,vector<int>&ans){
    ans.push_back(u);
    if(ans.size()==3) return ;
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
          vector<int>ans; bool po=false;
          FOR(i,0,n){ 
            if(!vis[i])
              dfs(i,adj,vis,ans);
            if(ans.size()==3){
              k--;
              res.push_back({ans[1]+1,ans[0]+1,ans[2]+1});
              int x = a[ans[0]],y=a[ans[1]],z=a[ans[2]];    
              if(po){
                  po=false; a[ans[0]]=ans[0];
                  vis[ans[1]]=0,vis[ans[2]]=0; a[ans[1]]=z;a[ans[2]]=x;
                  adj[z].clear(); adj[z].push_back(ans[1]);
                  adj[x].clear(); adj[x].push_back(ans[2]);
              }else {
                  if(a[ans[0]]==ans[2]){
                    vis[ans[2]]=1;a[ans[1]]=ans[1];a[ans[2]]=ans[2];a[ans[0]]=ans[0];
                  } else {
                    a[ans[2]]=x; a[ans[0]]=ans[0];a[ans[1]]=ans[1];
                    adj[x].clear(); adj[x].push_back(ans[2]);
                  }  
              }
            ans.clear();
            } else if(ans.size()==2) po =true; 
          //  FOR(i,0,n) cout<<a[i]+1<<" ";
          // cout<<"\n";   
          } po = true;
          FOR(i,0,n) if(a[i]!=i) po=false;
          x = res.size(); 
        //   FOR(i,0,n) if(adj[i].size()) cout<<i<<": "<<adj[i][0]<<"\n";
          if(k<0 || !po ) {cout<<-1<<"\n";continue;}
          cout<<x<<"\n";
          FOR(i,0,res.size())
            cout<<res[i].x<<" "<<res[i].y<<" "<<res[i].z<<"\n";
      }
  }
