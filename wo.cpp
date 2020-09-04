#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#include <__msvc_all_public_headers.hpp>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

typedef long long ll;

#define press_F_to_pay_respect        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define forn for (int i = 0; i < n; i++)
#define fore(i, a, b) for (int i = a; i < (b); i++)
#define pb push_back
#define pob pop_back()
#define mp make_pair
#define sc second
#define f first
#define ld long double
#define kek cout << "\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define all(v) ((v).begin()), ((v).end())
#define halt          \
    {                 \
        cout << "NO"; \
        return 0;     \
    }

const ll MOD = 1e9 + 7;
const ll MOD1 = 998244353;
const int N = 5010;
const int INF = 1e8;
const ll LL_INF = 1e18;
const long double pi = 3.1415926535;
using namespace std;
using namespace __gnu_pbds;
typedef tree<ld, null_type, less<ld>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
int divide(int a, int b)
{
    return (a + b - 1) / b;
}
vector<vector<ll>> adj;
vector<ll> dp;
vector<ll> g;
ll diam = 0;
vector<bool> nodes;
void dfs(int s, int e)
{
    dp[s] = 1;
    vector<ll> val;
    for (auto x : adj[s])
    {
        if (e == x)
            continue;
        dfs(x, s);
        val.pb(dp[x]);
    }
    sort(all(val));
    if (val.size())
        dp[s] += val.back();
    if (val.size() >= 2)
        g[s] = 1 + val.back() + val[val.size() - 2];

    diam = max(diam, max(dp[s], g[s]));
}
void dfs1(int s, int e)
{
    if (adj[s].size() == 1)
        nodes[s] = true;
    for (auto x : adj[s])
    {
        if (x == e)
            continue;
        if (dp[x] == dp[s] - 1)
            dfs1(x, s);
    }
}
int main()
{
#if defined(_DEBUG)
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    press_F_to_pay_respect;
    // cout << fixed << setprecision(12) << ans;
    // string al = "abcdefghijklmnopqrstuvwxyz";
    int questions = 1;
    // cin>>questions;
    while (questions--)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << 1;
            return 0;
        }
        adj.resize(n + 2);
        dp.resize(n + 2);
        g.resize(n + 2);
        nodes.resize(n + 2);
        int z = n - 1;
        while (z--)
        {
            int a, b;
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        dfs(1, 0);
        vector<ll> d = dp;
        // we have found diam == tree diameter
        for (int i = 1; i <= n; i++)
        {
            if (g[i] == diam)
            {
                dp.clear();
                dp.resize(n + 2);
                g.clear();
                g.resize(n + 2);
                // now lets root the tree on node i and count dp and g vectors
                dfs(i, 0);
                vector<int> val;
                // add in vector<int> val all dp values from other nodes
                for (auto x : adj[i])
                    val.pb(dp[x]);
                // then choose two maximum
                sort(all(val));
                int mx = val.back();
                int mx1 = val[val.size() - 2];
                // then do dfs1 to find leaves
                for (auto x : adj[i])
                {
                    if (dp[x] == mx || dp[x] == mx1)
                        dfs1(x, 0);
                }
                // if we have found needed nodes write them
            }
        }
        dp = d;
        // otherwise the tree is rooted in node 1 and we need to find leaves from here
        for (int i = 1; i <= n; i++)
        {
            if (dp[i] == diam)
            {
                // dfs from node i
                //cout<<"aaa1"<<" "<<i;
                nodes[i] = true;
                dfs1(i, 0);
                break;
            }
        }
        // we have found the answer, print it
        for (int i = 1; i <= n; i++)
        {
            if (nodes[i])
                cout << diam;
            else
                cout << diam - 1;
            kek;
        }
    }

    // !!! LOOK AT NUMBER OF QUESTIONS IN A PROBLEM !!! (cin>>questions)

    // cout <<"Runtime is:"<<clock() * 1.0 / CLOCKS_PER_SEC <<endl;
    return 0;
}