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

class PrimeTree
{
public:
    vector<bool> prime = vector<bool>(300, true);
    vector<int> adj[10 * 1000 * 10];
    vector<int> p = vector<int>();

    void s()
    {
        for (int p = 2; p * p <= 300; p++)
        {
            if (prime[p])
                for (int i = p * p; i <= 300; i += p)
                    prime[i] = false;
        }
        FOR(i, 2, 100)
        if (prime[i])
            p.push_back(i);
    }

    void dfs(int u, int pp, vector<bool> &vis, vector<vector<LL>> &dp)
    {
        vis[u] = 1;
        FOR(i, 0, (int)p.size())
        dp[u][i] = 1;

        for (auto v : adj[u])
        {
            if (vis[v])
                continue;
            dfs(v, u, vis, dp);
            FOR(i, 0, (int)p.size())
            {
                LL s = 0;
                FOR(j, 0, (int)p.size())
                {
                    if (!prime[p[i] + p[j]])
                        s = (s + dp[v][j]) % mod;
                }
                dp[u][i] = (dp[u][i] * s) % mod;
            }
        }
    }
    int getNumberOfArrangements(int N, std::vector<std::vector<int>> edges)
    {
        int n = N;
        FOR(i, 0, n - 1)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        s();
        vector<vector<LL>> dp(100, vector<LL>(100, 0));
        vector<bool> vis(100, false);
        dfs(0, -1, vis, dp);
        LL ans = 0;
        FOR(i, 0, (int)p.size())
        ans = (ans + dp[0][i]) % mod;
        return ans;
    }
};

int main()
{
    fastio;
    int t = 1; // cin>>t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> v;
        FOR(i, 0, n - 1)
        {
            int x, y;
            cin >> x >> y;
            v.push_back({x, y});
        }
        PrimeTree p;
        cout << p.getNumberOfArrangements(n, v);
    }
}
