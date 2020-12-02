#include <bits/stdc++.h>
using namespace std;

#define fastio                  \
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

LL fun(int i, int j, vector<vector<LL>> &p)
{
  LL s = 0, res = -INF, cur = 0;
  int n = p.size();
  while (i >= 0 && j < n)
  {
    s += p[i][j];
    cur = min(cur, s);
    res = max(res, s - cur);
    i--, j++;
  }
  return res;
}
int main()
{
  fastio;
  int t = 1; // cin>>t;
  while (t--)
  {
    int n;
    cin >> n;
    LL a[n];
    FOR(i, 0, n)
        cin >> a[i];
    vector<vector<LL>> p(n, vector<LL>(n));
    FOR(i, 0, n)
    FOR(j, 0, n) p[i][j] = a[i] * a[j];
    LL res = -INF;
    FOR(i, 0, n)
    {
      res = max({res, fun(i - 1, i, p), fun(i - 1, i + 1, p)});
    }
    cout << res;
  }
}
