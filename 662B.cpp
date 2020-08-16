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
#define FOR(i, j, k) for (auto i=j ; i<k ; i++)

const long long MAX = 2e5+10;
bool prime[MAX]; 

void Si(){ 
    memset(prime, true, sizeof(prime));   
    for (int p=2; p*p<MAX; p++)     
        if (prime[p] == true)         
            for (int i=p*p; i<MAX; i += p) 
                    prime[i] = false; 
} 

int main(){
    fastio;
    int t=1; //cin>>t;
    while(t--){
        int n,q; cin>>n; int a[n],cnt[MAX]={0};

        FOR(i,0,n) cin>>a[i],cnt[a[i]]++;
        cin>>q;
        set<pair<int,int>>s;
        FOR(i,0,MAX) if(cnt[i]) s.insert({cnt[i],i});

        FOR(i,0,q) {
            char ch; int v; cin>>ch>>v;
            if(ch=='+') {
                auto it = s.find({cnt[v],v});
                if(it!=s.end()) s.erase(it);
                s.insert({++cnt[v],v});
            }else {
                s.erase(s.find({cnt[v],v}));
                if(--cnt[v]) s.insert({cnt[v],v});
            }
            //for(auto j : s) cout<<j.first<<" "<<j.second<<" ; ";
            if(s.size()==2){
                auto it = --s.end();
                int p=it->first;
                --it; int q=it->first;
             //   cout<<p<<" "<<q<<" ";
                if((p>=4 && q>=4) || (p>=6 && q>=2) || (p>=8)) cout<<"YES\n";
                else cout<<"NO\n"; 
            }else if(s.size()>=3) {
                 auto it = --s.end();
                 int p=it->first; 
                --it; int q=it->first; --it; int r = it->first;
                 if((p>=4 && q>=4) || (p>=6 && q>=2) || (p>=4 && q>=2 && r>=2) || (p>=8)) cout<<"YES\n";
                else cout<<"NO\n";
            }else if(s.size()) {
                auto it = s.begin();
                if(it->first>=8) cout<<"YES\n";
                else cout<<"NO\n";
            }else cout<<"NO\n";
        }
    }
}
