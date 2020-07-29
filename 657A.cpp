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
 
#define fff ios_base::sync_with_stdio(0); cin.tie(0)
#define LL long long 
#define mod 1000000007 
#define FOR(i, j, k) for (auto i=j ; i<k ; i++)
#define ROF(i, j, k) for (auto i=j ; i>=k ; i--) 
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false); debug("%s time : %.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))

const long long INF = 1e18;
const long long MAX = 1e5+10;
void dfs(int u , vector<pair<int,int>>adj[],vector<int>&vis,vector<pair<int,int>>&res,int dir){
  
      vis[u]=1;
      for(auto v : adj[u]) {
          if(v.first == 0) {
              if(dir==0) {
                  dir=0;
              }
          }else if(v.first==1){
             
          }else {vis[u]=0; return;}
      }int t=1;
        while(t--){
        int n,x;cin>>n>>x;
        int a[n]; FOR(i,0,n) cin>>a[i];
        sort(a,a+n);
        int b[n];
        ROF(i,n-1,0){
          int sm = a[i];
          int j = ceil((float)x/a[i]);
          b[i] = j;
        }
        int dp[n+100]={0};
        ROF(i,n-1,0){
          if(b[i]+i<=n) dp[i]=1+dp[b[i]+i];
          else dp[i]=0;
        }
        cout<<*max_element(dp,dp+n)<<"\n";
    }
}
int main(){
    fff;
    int t; cin>>t;
    while(t--){
        string s; int n; cin>>n>>s; string m="abacaba";
        bool pos = true;
        string ans; int val=0; int d=0;
        FOR(j,0,n) {
            string tt;
            FOR(k,j,min(j+m.size(),s.size()))  tt+=s[k];
            if(tt==m) d++;
        }
        if(d>1) {cout<<"NO\n"; continue;}
        if(d==1) {FOR(i,0,n) if(s[i]=='?') s[i]='d';  cout<<"YES\n"<<s<<"\n"; continue; }

        FOR(i,0,n) {
            string temp  = s;
            temp.insert(i,m);temp.erase(i+m.size(),m.size());
            FOR(j,0,n) {
                if(s[j]=='?' ) continue;
                else if(s[j]!='?') {
                    if(temp[j]=='?') pos = false;
                    else if(temp[j]==s[j]) continue;
                    else pos =false;
                } else pos = false; 
            }
         //   cout<<temp<<" ";
            FOR(j,0,n) {
                string tt;
                FOR(k,j,min(j+m.size(),s.size()))  tt+=temp[k];
                if(tt==m) d++;
            }
            if(pos && d==1) {ans=temp; val=1; break;}
            pos=true; d=0;
        } 
        FOR(i,0,ans.size()) if(ans[i]=='?') ans[i]='d';

        if(val) {
            cout<<"YES\n";
            FOR(i,0,n) cout<<ans[i];
            cout<<"\n";
        }else cout<<"NO\n";
    }
}
