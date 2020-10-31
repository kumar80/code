#include <bits/stdc++.h>
#define FOR(i, j, k) for (auto i = j; i < k; i++)

using namespace std;
void find_min_days(int p[], int c[], int n, int d)
{
    vector<pair<int, int>> v;
    FOR(j, 0, d)
    {
        map<int, int> m;
        bool ok = false;
        FOR(i, 0, n)
        {
            int x = -c[j] + p[i];
            if (m[x] != 0)
            {
                v.push_back({m[x], i + 1});
                ok = true;
                break;
            }
            m[p[i]] = i + 1;
        }
        if (!ok)
            v.push_back({-1, -1});
    }
    int l = v.size();
    FOR(i, 0, l - 1)
    {
        if (v[i].first != -1)
            cout << v[i].first << " " << v[i].second << ",";
        else
            cout << -1 << ",";
    }
    if (v[l - 1].first != -1)
        cout << v[l - 1].first << " " << v[l - 1].second;
    else
        cout << -1;
}

int main()
{
    int n, d, i;
    cin >> n >> d;
    int price[n];
    int profit[d];
    for (i = 0; i < n; i++)
        cin >> price[i];
    for (i = 0; i < d; i++)
        cin >> profit[i];
    find_min_days(price, profit, n, d);

    // Do not remove below line
    //	cout<<answer<<endl;
    // Do not print anything after this line

    return 0;
}