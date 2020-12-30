#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    char x = ' ';
    int y;
    cin >> noskipws;
    while (x != '\n')
    {
        cin >> y;
        v.push_back(y);
        cin >> x;
    }
    int tr;
    cin >> tr;
    int l = 0, r = v.size() - 1;
    int ans = -1;
    while (l <= r)
    {
        int m = (l + r) / 2;

        if (v[m] >= tr)
            ans = m, r = m - 1;
        else
            l = m + 1;
    }
    if (ans == -1)
        cout << -1;
    else
        cout << ans;
}