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

struct rec
{
    LL l, w, h;
};
LL mul(LL x, LL y)
{
    return ((x * y) % mod + mod) % mod;
}
LL add(LL x, LL y)
{
    return ((x + y) % mod + mod) % mod;
}

bool cmp(rec a, rec b)
{
    return a.l <= b.l;
}
int main()
{
    fastio;
    int t = 1, T = 1;
    cin >> t;
    while (t--)
    {
        LL n, k, al, bl, cl, dl, ah, bh, ch, dh, aw, bw, cw, dw;
        cin >> n >> k;
        LL l[n], h[n], w[n];
        vector<rec> v(n);
        FOR(i, 0, k)
        cin >> v[i].l;
        cin >> al >> bl >> cl >> dl;
        FOR(i, k, n)
        v[i].l = (al * v[i - 2].l + bl * v[i - 1].l + cl) % dl + 1;

        FOR(i, 0, k)
        cin >> v[i].w;
        cin >> aw >> bw >> cw >> dw;
        FOR(i, k, n)
        v[i].w = (aw * v[i - 2].w + bw * v[i - 1].w + cw) % dw + 1;

        FOR(i, 0, k)
        cin >> v[i].h;
        cin >> ah >> bh >> ch >> dh;
        FOR(i, k, n)
        v[i].h = (ah * v[i - 2].h + bh * v[i - 1].h + ch) % dh + 1;

        LL prev = 0, hmax = v[0].h, lmin = v[0].l, lmax = v[0].l + v[0].w;
        LL ans = (2 * (v[0].w + v[0].h)) % mod, cnt1 = 0, cnt2 = 0, cnt3 = 0;
        prev = 0;
        cout << ans << "\n";
        FOR(i, 1, n)
        {
            LL ar;
            if (lmax < v[i].l)
            {
                prev = add(prev, 2 * (lmax - lmin + hmax));
                ar = prev + 2 * (v[i].h + v[i].w);
                hmax = v[i].h;
                lmin = v[i].l, lmax = v[i].l + v[i].w;
                ans = mul(ans, ar);
            }
            else
            {
                hmax = max(v[i].h, hmax);
                lmax = max(v[i].l + v[i].w, lmax);
                ar = prev + 2 * (lmax - lmin + hmax); //add(prev,mul(2,add(lmax-lmin,hmax)));
                ans = mul(ans, ar);
            }
            cout << ar << "\n";
        }
        cout << "Case #" << T++ << ": ";
        cout << ans << " " << cnt1 << " " << cnt2 << " " << cnt3 << " "
             << "\n";
    }
}
