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
        int n ; cin>>n;  int e  = (n+1)/2,o=n/2; int a[n];
        int eo=0,oe=0; 
        FOR(i,0,n) {
            cin>>a[i];
            if(a[i]&1) o--;
            else e--;
            if(i&1 && a[i]%2==0) oe++;
            if(i%2==0 && a[i]&1) eo++;
        }
        if(oe!=eo) {cout<<-1<<"\n"; continue;}
        cout<<eo<<"\n";

    }
}
