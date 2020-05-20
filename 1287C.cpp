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

int main(){
    fastio;
    int t=1; //cin>>t;
    while(t--){
        int n; cin>>n; int a[n];
        vector<int>odds,evens;
        vector<int>x(101,1);
        FOR(i,0,n) {cin>>a[i]; x[a[i]] =0;}
        FOR(i,1,n+1){
            if(x[i] && i&1) odds.push_back(i);
            if(x[i] && i%2==0) evens.push_back(i);
        }
        int i=0;deque<pair<int,int>>o,e;
     
        FOR(j,0,n){
            if(a[j]==0) continue;
            if(a[j]&1 && (a[i]==0 || a[i]&1)) { if(a[i]==0) o.push_back({i,j}); else o.push_back({i+1,j}); i=j;}
            else if(a[j]%2==0 && (a[i]==0 || a[i]%2==0)){ if(a[i]==0) e.push_back({i,j}); else e.push_back({i+1,j}); i=j;}
            else i=j;
        }
        if(a[n-1]==0 && a[i]&1 && a[i]) o.push_front({i+1,n});
        else if(a[n-1]==0 && a[i]%2==0 && a[i]) e.push_front({i+1,n});
   // cout<<odds.size()<<" "<<endl; FOR(i,0,odds.size()) cout<<odds[i]<<" ";
     //   cout<<endl<<evens.size()<<" "<<endl; FOR(i,0,evens.size()) cout<<evens[i]<<" ";

        while(!o.empty()){
           int l=o.front().first,r=o.front().second;
//            cout<<l<<" lr "<<r<<endl;

           for(int k=r-1;k>=l;k--) {
               if(a[k]) continue;
               if(odds.size()>0){
                   a[k] = *odds.begin();
                   odds.erase(odds.begin());
               }
           }
           o.pop_front();
       }
        while(!e.empty()){
           int l=e.front().first,r=e.front().second;
//           cout<<l<<" lr "<<r<<endl;
           for(int k=r-1;k>=l;k--) {
               if(a[k]) continue;
               if(evens.size()>0){
                   a[k] = *evens.begin();
                   evens.erase(evens.begin());
               }
           }
           e.pop_front();
       }

   // FOR(k,0,n)            cout<<a[k]<<" ";

      //cout<<odds.size()<<" "<<endl; FOR(i,0,odds.size()) cout<<odds[i]<<" ";
     //   cout<<endl<<evens.size()<<" "<<endl; FOR(i,0,evens.size()) cout<<evens[i]<<" ";

    cout<<endl;
       FOR(k,0,n) {
           if(a[k]) continue;
           if(evens.size()==0 || 
           (odds.size()>0 && (k==0 || a[k-1]&1))) {a[k]=*odds.begin(); odds.erase(odds.begin()); }
           else  if(odds.size()==0 ||
            (evens.size()>0 && (k==0 || a[k-1]%2==0))) {a[k]=*evens.begin(); evens.erase(evens.begin());}
            
       }

     // FOR(k,0,n)            cout<<a[k]<<" ";
   // cout<<endl<<"****";
       int ans=0;
       FOR(j,0,n-1){
         if((a[j]+a[j+1]) &1) {cout<<a[j]<<" "<<a[j+1]<<endl;ans++;}
       }
       cout<<ans;
    }
}
