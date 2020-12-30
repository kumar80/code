#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(b.begin(), b.end(), b.begin(), ::tolower);

    int ans = 0;
    map<char, int> ma, mb, m;
    for (int i = 0; i < max(a.size(), b.size()); i++)
    {
        if (i < a.size() && i < b.size())
        {
            if (a[i] == b[i])
                ans += 2, m[a[i]]++;
            else
            {
                ma[a[i]]++, mb[b[i]]++;
            }
        }
        else if (i < a.size())
            ma[a[i]]++;
        else
            mb[b[i]]++;
    }

    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        ans += min(ma[ch], mb[ch]);
    }
    cout << ans;
}

