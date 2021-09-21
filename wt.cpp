#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
#define LL long long
#define mod 1000000007
#define FOR(i, j, k) for (int i = j; i < k; i++)
#define ROF(i, j, k) for (int i = j; i >= k; i--)
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d) for (long blockTime = 0; (blockTime == 0 ? (blockTime = clock()) != 0 : false); debug("%s time : %.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))

const long long INF = 1e18;
const long long MAX = 1e5 + 10;
vector<int> l;
void dfs(int u, vector<int> adj[], vector<int> &vis, int c, int p)
{
    vis[u] = 1;
    for (auto v : adj[u])
        if (!vis[v])
            dfs(v, adj, vis, c + 1, u);
        else if (v != p && c >= 2)
            l.push_back(c);
}
int main()
{
    fastio;
    int t = 1, T = 1;
    cin >> t;
    while (t--)
    {
        LL n;
        cin >> n;
        string s;
        cin >> s;
        vector<LL> p(n + 71, 0),dp(n+7,0);
        char ch = s[n-1];
        int sum = 0;
        ROF(i, n-2, 0)
        {
           // p[i] = p[i + 1];
            if(ch == 'F') ch = s[i];
            if ((ch == 'X' && s[i] == 'O') || (ch == 'O' && s[i] == 'X'))
                p[i]++, ch = s[i];
            sum+=p[i];
            if(p[i]) dp[i] = dp[i+1] + ;
            else dp[i]  = dp[i+1];
        }
        // ROF(i,n-2,0) 
        //     p[i]  = (p[i] + p[i+1])%mod;

        LL ans = 0;         
        FOR(i, 0, n)
        {
            ans = ((ans + p[i]) % mod + mod) % mod;
        }
        cout << "Case #" << T++ << ": " << ans << "\n";
    }
}
