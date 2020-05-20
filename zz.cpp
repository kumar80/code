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
int main(){
    fastio;
    int t=1; cin>>t;
    while(t--){
        int n; string s ; cin>>s; n=s.size();
        vector<int>k[4]; int ans  = INT_MAX;
        FOR(i,0,n) 
            k[s[i]-'0'].push_back(i);
        FOR(i,0,n){
            if(s[i]=='1'){
                int l=0,r=k[2].size()-1,tw=-1;
                while(l<=r){
                    int m = l +(r-l)/2;
                    if(k[2][m]>=i) {tw=k[2][m]; r=m-1;}
                    else l=m+1;
                }l=0,r=k[3].size()-1;int th=-1; 
                while(l<=r){
                    int m = l +(r-l)/2; 
                    if(k[3][m]>=i) {th=k[3][m]; r=m-1;}
                    else l=m+1;//cout<<th<<" "<<k[3][m];
                } //cout<<tw<<" "<<th; 
                if(tw!=-1 && th!=-1)  ans = min(ans,max(tw,th)-i+1); 
            }   if(s[i]=='2'){
                int l=0,r=k[1].size()-1,tw=-1;
                while(l<=r){
                    int m = l +(r-l)/2;
                    if(k[1][m]>=i) {tw=k[1][m]; r=m-1;}
                    else l=m+1;
                }l=0,r=k[3].size()-1;int th=-1;
                while(l<=r){
                    int m = l +(r-l)/2;
                    if(k[3][m]>=i) {th=k[3][m]; r=m-1;}
                    else l=m+1;
                }
                if(tw!=-1 && th!=-1)  ans = min(ans,max(tw,th)-i+1); 
            }   if(s[i]=='3'){
                int l=0,r=k[2].size()-1,tw=-1;
                while(l<=r){
                    int m = l +(r-l)/2;
                    if(k[2][m]>=i) {tw=k[2][m]; r=m-1;}
                    else l=m+1;
                }l=0,r=k[1].size()-1;int th=-1;
                while(l<=r){
                    int m = l +(r-l)/2;
                    if(k[1][m]>=i) {th=k[1][m]; r=m-1;}
                    else l=m+1;
                }
                if(tw!=-1 && th!=-1)  ans = min(ans,max(tw,th)-i+1); 
            }
        }
        if(ans!=INT_MAX)
        cout<<ans<<"\n";
        else cout<<0<<"\n";
    }
}
