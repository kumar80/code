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

vector<int> adj[MAX];
vector<bool> vis(MAX, false);
stack<int> st;
void dfs(int u)
{
    vis[u] = 1;
    for (auto v : adj[u])
    {
        if (vis[v])
            continue;
        dfs(v);
    }
    st.push(u);
}
int main()
{
    fastio;
    int t = 1; //cin>>t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        FOR(i, 0, m)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
        }
        int s, e;
        cin >> s >> e;
        dfs(s);
        vector<LL> dp(MAX, 0), l;
        dp[e] = 1;
        while (!st.empty())
        {
            l.push_back(st.top());
            st.pop();
        }
        for (int i = l.size() - 1; i >= 0; i--)
        {
            for (int j = 0; j < adj[l[i]].size(); j++)
            {
                dp[l[i]] = (dp[l[i]] +  dp[adj[l[i]][j]])%mod;
            }
        }
        cout << dp[s] << "\n";
    }
}
