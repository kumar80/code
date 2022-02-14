#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for (auto i = j; i < k; i++)
vector<int> f(int n, int a, int b, int c)
{
    vector<int> v(n, 0);
    for (int i = 0; i < 30; i++)
    {
        int b1 = (1 << i) & a ? 1 : 0, b2 = (1 << i) & b ? 1 : 0, b3 = (1 << i) & c ? 1 : 0;
        if (b1 + b2 + b3 == 0)
            continue;
        if (b1 + b3 == 0 && b2 == 1)
        {
            if (n < 3)
                return vector<int>(1, -1);
            v[0] = v[0] | (1 << i);
            v[1] = v[1] | (1 << i);
        }
        else if (b1 + b2 == 2 && b3 == 0)
        {
            if (n & 1)
                return vector<int>(1, -1);
            for (int j = 0; j < n; j++)
                v[j] |= (1 << i);
        }
        else if (b1 == 0 && b2 + b3 == 2)
        {
            if (n == 1)
                return vector<int>(1, -1);
            v[0] |= (1 << i);
        }
        else if (b1 + b2 + b3 == 3 && n&1)
        {
            for (int j = 0; j < n; j++)
                v[j] |= (1 << i);
        }
        else
            return vector<int>(1, -1);
    }
    sort(v.begin(), v.end());
    return v;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        auto v = f(n, a, b, c);
        for (auto i : v)
            cout << i << " ";
        cout << "\n";
    }
}
