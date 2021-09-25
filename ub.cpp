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
vector<char>sol;
struct test{
    string S;
    string T;
    int k;
};

LL sumOdd(LL n){
    return n*n;    
}
LL sumEven(LL n ){
    return n*(n+1);
}

char findsol(test t){
    string s; int i=1,j=2,ch=1;
    while(s.size()<=t.k){
        if(ch){
            FOR(k,0,i) s+=t.S;
            i+=2;
            ch = 0;
        }else {
            FOR(k,0,j) s+=t.T;
            j+=2;
            ch = 1;
        }
    }
    return s[t.k-1];    
}

int main(){
    fastio;
    vector<test>v; 
    v.push_back({"abc","def",7});
    v.push_back({"sdsa","drasdarrrd",9});
    v.push_back({"sdsasa","dasdaaad",10});
    v.push_back({"sdsadas","dasdaddfee",11});
    v.push_back({"abc","deggf",20}); // abcdeggfdeggfabcabc abc
    v.push_back({"sdstya","dasdadpspps",800});
    v.push_back({"pipsdsa","owcnczpdasdad",98});
    v.push_back({"sqssdsa","dopwtyycbasdad",898});
    v.push_back({"zszdcxsa","dasdfoewriad",801});
    v.push_back({"scddsa","dasdaoobygdcd",8000});
    v.push_back({"sdasdsdea","eyetydasdad",788});
    for(auto r : v){
         sol.push_back(findsol(r));
    }
    int c= v.size()-1;
    while(c>=0){
        int k=v[c].k; string S=v[c].S,T=v[c].T; //cin>>S>>T>>k;
        LL l = 0, r = 1e4;
        int s = S.size(),t = T.size(),ans = -1;
        while(l<=r){
            LL m = (l+r)/2;
            LL tt = sumOdd((m+1)/2) * s + sumEven( m/2) * t;
         //   cout<<tt<<" "<<m<<endl;
            if(tt<=k){
                ans = m; l=m+1;
            }else r=m-1;
        }
        k-=  sumOdd((ans+1)/2) * s + sumEven( ans/2) * t;
      //  cout<<ans<<" ";
        if(ans%2==0){
        //    cout<<k<<" "<<S<<" ";
            k+=s-1;
            cout<<S[k%s];
        }else {
            k+=t-1;
            cout<<T[k%t];
        }
        cout<<" "<<sol[c]<<endl;
        c--;
    }
}
