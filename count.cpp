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
#include<iostream> 
using namespace std; 

long long  power(long long  x,  long long  y,  long long  m){ 
	if (y == 0) 
		return 1; 
	long long  p = power(x, y/2, m) % m; 
	p = (p * p) % m; 

	return (y%2 == 0)? p : (x * p) % m; 
} 

 long long gcd(long long  a, long long  b){ 
	if (a == 0) 
		return b; 
	return gcd(b%a, a); 
} 

long long  modInverse(long long  a, long long  m){ 
	long long  g = gcd(a, m); 
	if (g != 1) 
        return -1;	
    else
	     return power(a, m-2, m); 	 
} 

int main(){
    fastio;
    long long n,k,mod=1e9+7; cin>>n>>k;
    long long f[100000],fInv[100000]; f[0]=1;
    for(int i=1;i<100000;i++) f[i] = (i*f[i-1])%mod; 
    for(int i=0;i<100000;i++) fInv[i]= modInverse(f[i],mod);
    long long ans =0;
    if(n==1) {cout<<10/k; return 0;}
    if(n&1){
        for(int sum=k;sum<=n*9;sum+=k)
            for(int i=1;i<10;i++){
                int y=sum-i;
                if(y>=0 && y%2==0 && y/2<=9*(n/2)) {
                    y/=2; y=y-(n-1)/2;
                    long long temp =(f[y+n/2-1]*fInv[y])%mod;
                    temp = (temp*fInv[n/2-1])%mod;
                    ans = (ans+temp)%mod;
                    cout<<sum<<" "<<i<<" ";
                }
            }
    }
    else {
        for(int sum=k;sum<=n*9;sum+=k){
                int y=sum;
                if(y>=0 && y%2==0 && y/2<=9*(n/2)) {
                    y/=2;y-=n/2;
                    long long temp = (f[y+n/2-1]*fInv[y])%mod; 
                    temp = (temp*fInv[n/2-1])%mod;
                    ans = (ans+temp)%mod;
                    cout<<sum<<" "<<ans<<" ";

                }
            }            
    }   

    cout<<ans;
}
