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
#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
#define LL long long
#define mod 1000000007
#define all(v) v.begin(), v.end()
#define pr(v) pair<v, v>
#define pb push_back
#define FOR(i, j, k) for (auto i = j; i < k; i++)
#define ROF(i, j, k) for (auto i = j; i >= k; i--)
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d) for (long blockTime = 0; (blockTime == 0 ? (blockTime = clock()) != 0 : false); debug("%s time : %.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))

const long long INF = 1e18;
const long long MAX = 2e5 + 10;
LL mul(LL x, LL y)
{
    return ((x * y) % mod + mod) % mod;
}
LL add(LL x, LL y)
{
    return ((x + y) % mod + mod) % mod;
}
int main()
{
    fastio;
    int t = 1, T = 1;
    cin >> t;
    while (t--)
    {
        LL n, k, w, al, bl, cl, dl, ah, bh, ch, dh;
        cin >> n >> k >> w;
        LL l[n], h[n];
        FOR(i, 0, k)
            cin >> l[i];
        cin >> al >> bl >> cl >> dl;
        FOR(i, k, n)
        l[i] = (al * l[i - 2] + bl * l[i - 1] + cl) % dl + 1;
        //add((mul(al,l[i-2]),add(mul(bl,l[i-1]),cl))%dl,1),cout<<l[i]<<", ";
        FOR(i, 0, k)
            cin >> h[i];
        cin >> ah >> bh >> ch >> dh;
        FOR(i, k, n)
        h[i] = (ah * h[i - 2] + bh * h[i - 1] + ch) % dh + 1;
        //add((mul(ah,h[i-2]), add(mul(bh,h[i-1]),ch))%dh,1),cout<<h[i]<<", ";
        LL prev = 0, hmax = h[0], lmin = l[0], lmax = l[0] + w;
        cout << "\n";
        LL ans = (2 * (w + h[0])) % mod;
        prev = 0;
        FOR(i, 1, n)
        {
            LL ar;
            if (lmax < l[i])
            {
                prev += 2 * (lmax - lmin + hmax); //add(prev,mul(2,add(lmax-lmin,hmax)));
                ar = prev + 2 * (h[i] + w);       //add(prev,mul(2,add(w,h[i])));
                hmax = h[i];
                lmin = l[i], lmax = l[i] + w;
                ans = mul(ans, ar);
            }
            else
            {
                hmax = max(h[i], hmax);
                lmax = max(l[i] + w, lmax);
                ar = prev + 2 * (lmax - lmin + hmax); //add(prev,mul(2,add(lmax-lmin,hmax)));// cout<<"ar "<<ar<<"\n";
                ans = mul(ans, ar);
            }

            // 50 10 17
            // 4 9 10 26 28 59 97 100 105 106
            // 1 0 7 832
            // 130 12 82 487 12 30 214 104 104 527
            // 21 81 410 605
        }
        cout << "Case #" << T++ << ": ";
        cout << ans << "\n";
    }
}
