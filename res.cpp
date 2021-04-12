#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for (auto i = j; i < k; i++)
#define time__(d) for (long blockTime = 0; (blockTime == 0 ? (blockTime = clock()) != 0 : false); debug("%s time : %.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

int main()
{
    int m;
    cin >> m;
    int ans = 0;
    time__("code")
    {
        FOR(i, 1, m)
        {
            int f = i, s = m - i;
            set<int> a; a.insert(1); a.insert(f);
            for (int j = 2; j * j <= f; j++)
            {
                if (f % j == 0)
                {
                    if (j * j == f)
                        a.insert(j);
                    else
                        a.insert(j), a.insert(f / j);
                }
            }
            ans+=distance(a.begin(),a.lower_bound(s));
            
            for (int j = 2; j * j <= s; j++)
            {
                if (s % j == 0)
                {
                    if (j * j == s)
                    {
                        auto it = a.lower_bound(j);
                        ans += distance(a.begin(), it);
                    }
                    else
                    {
                        auto it = a.lower_bound(j);
                        auto it2 = a.lower_bound(s / j);
                        ans += distance(a.begin(), it) + distance(a.begin(), it2);
                    }
                }
            }
        }
    }
    cout << ans;
}