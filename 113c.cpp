#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
#define LL long long
#define mod 998244353
#define FOR(i, j, k) for (int i = j; i < k; i++)
#define ROF(i, j, k) for (int i = j; i >= k; i--)
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d) for (long blockTime = 0; (blockTime == 0 ? (blockTime = clock()) != 0 : false); debug("%s time : %.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))

const long long INF = 1e18;
const long long MAX = 1e5 + 10;
int gcd(int a, int b);

// To compute x raised to power y under modulo m
int power(int x, unsigned int y, unsigned int m);

long long calculate(long long p,
                    long long q)
{
    long long expo;
    expo = mod - 2;

    // Loop to find the value
    // until the expo is not zero
    while (expo)
    {

        // Multiply p with q
        // if expo is odd
        if (expo & 1)
        {
            p = ((p * q) % mod + mod)%mod;
        }
        q = ((q * q) % mod + mod)%mod;

        // Reduce the value of
        // expo by 2
        expo >>= 1;
    }
    return p;
}

int main()
{
    fastio;
    int t;
    cin >> t;
    LL p[2 * MAX];
    p[0] = 1;
    FOR(i, 1, 2 * MAX)
    p[i] = ((i * p[i - 1]) % mod + mod)%mod;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        map<int, int> m;
        FOR(i, 0, n)
        cin >> a[i],
            m[a[i]]++;
        sort(a, a + n);
        if (n == 1)
        {
            if (m[a[0]] > 1)
                cout << 0 << "\n";
            else
                cout << 1 << "\n";
            continue;
        }
        if (a[n - 1] - a[n - 2] > 1)
        {
            cout << 0 << "\n";
            continue;
        }
        if (m[a[n - 1]] > 1)
        {
            cout << p[n] << "\n";
            continue;
        }
        LL l = p[n - m[a[n - 2]] - 1], k = m[a[n - 2]];
        LL ans = 0;
        FOR(i, k, n)
        {
            int r = calculate(p[i], p[i - k]);
            r = ((r * l) % mod + mod)%mod;
            ans += r;
        }
        ans = ((p[n] - ans) % mod + mod) % mod;
        cout << ans << "\n";
    }
}