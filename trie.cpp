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

struct trie
{   int v;
    trie *bit[2];
    trie()
    {
        this->bit[0] = this->bit[1] = NULL;
    }
    trie(int d){
        this->v = d;
        this->bit[0] = this->bit[1] = NULL;
    }
};

void insert(trie *root, int v)
{
    ROF(i,31,0){
        bool j = ((1<<i) & v);
        if(root->bit[j]==NULL)
            root->bit[j] = new trie();

        root=root->bit[j];
    }
    root->v=v;
}
LL res = 0;
void x(trie *root, int v)
{   
    ROF(i,31,0) {
         bool j = (1<<i & v);

        if(root->bit[1-j]!=NULL)
            root=root->bit[1-j] , res =( res | (1<<i));  
        else if(root->bit[j]!=NULL) 
            root=root->bit[j];     
    }
    //cout<<root->v;
}

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
    {
        trie *root = new trie();
        int n=6; 
        cin >> n;
        LL a[n],ans=0;
        FOR(i, 0, n)
        {
            cin >> a[i];
            if(i>0) x(root,a[i]);
            ans = max(res, ans); res=0;
            insert(root, a[i]);
        }
        cout << ans << " ";
    }
}
