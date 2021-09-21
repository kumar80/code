#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
#define LL long long
#define mod 998244353
#define FOR(i, j, k) for (int i = j; i < k; i++)
#define ROF(i, j, k) for (int i = j; i >= k; i--)

const long long INF = 1e18;
const long long MAX = 1e5 + 10;

int main()
{
    fastio;
    int t = 1; // cin>>t;
    while (t--)
    {
        int n;
        cin >> n;
        LL a[n + 1];
        FOR(i, 1, n + 1)
            cin >> a[i];
        LL dp[n + 1][2];
        dp[1][1] = 1;
        dp[1][0] = a[1] - 1;
        FOR(i, 2, n + 1)
        {
            dp[i][1] = dp[i-1][0];
            dp[i][0] = dp[i-1][1]*(a[i]-1) + (a[i] <2 ? 0 : dp[i-1][0]*(a[i]-2));
        }
        cout << dp[n][0]+dp[n][1];
    }
}
2 3 2

1 3 1
1 1 3
