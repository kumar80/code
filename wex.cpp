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

LL a, b, c, d;
LL power(LL x, LL n)
{
    LL result = 1;
    while (n)
    {
        if (n & 1)
            result = (result * x) % mod;
        x = (x * x) % mod;
        n = n >> 1;
    }
    return result;
}

void fast_fib(long long int n, long long int ans[])
{
    if (n == 0)
    {
        ans[0] = 0;
        ans[1] = 1;
        return;
    }
    fast_fib((n / 2), ans);
    a = ans[0]; /* F(n) */
    b = ans[1]; /* F(n+1) */
    c = 2 * b - a;
    if (c < 0)
        c += mod;
    c = (a * c) % mod;         /* F(2n) */
    d = (a * a + b * b) % mod; /* F(2n + 1) */
    if (n % 2 == 0)
    {
        ans[0] = c;
        ans[1] = d;
    }
    else
    {
        ans[0] = d;
        ans[1] = c + d;
    }
}
int main()
{
    fastio;
    int q = 1; //cin>>t;
    
    while (q--)
    {
        LL v, x, y, i, j;
        cin >> v >> x >> y;
        LL ans[2] = {0};
        fast_fib(x, ans);
        a = ans[0];
        b = ans[1];
        LL t = 0;
        for (i = x; i <= y; i++)
        {
            c = a + b;
            LL k = 1;
            a = b;
            b = c;
            if (c < v)
                continue;
            for (j = 0; j < v; j++)
            {
                k *= (c - j);
                k %= mod;
            }
            t += k;
            t %= mod;
        }
        LL z = 1;
        for (i = 1; i <= v; i++)
        {
            z *= (power(i, mod - 2));
            z %= mod;
        }
        t *= z;
        t %= mod;
        cout << t;
    }
}
