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

LL ans = INT_MIN;
bool isOp(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool prio(char c)
{
    if (c == '+' || c == '-')
        return 1;
    return 2;
}

long long cal(LL a, LL b, char o)
{
    if (o == '+')
        return a + b;
    if (o == '-')
        return a - b;
    if (o == '*')
        return a * b;
    return a / b;
}

void eval(string s)
{
    int n = s.size();
    if (isOp(s[0]) || isOp(s[n - 1]))
        return;
    for (int i = 0; i < n - 1; i++)
        if (isOp(s[i]) && isOp(s[i + 1]))
            return;
    vector<LL> v;
    string op;
    LL a = 0;
    for (int i = 0; i < n; i++)
    {
        if (isOp(s[i]))
        {
            v.push_back(a);
            a = 0;
            op += s[i];
        }
        else
            a = a * 10 + (s[i] - '0');
    }
    v.push_back(a);
    if (op.size() == 1)
    {
        ans = max(ans, cal(v[0], v[1], op[0]));
    }
    else
    {
        if (prio(op[0]) >= prio(op[1]))
        {
            LL temp = cal(v[0], v[1], op[0]);
            temp = cal(temp, v[2], op[1]);
            ans = max(ans, temp);
        }
        else
        {
            LL temp = cal(v[1], v[2], op[1]);
            temp = cal(v[0], temp, op[0]);
            ans = max(ans, temp);
        }
    }
}
LL cnt = 0;
void permute(string s, string answer)
{
    if (s.length() == 0)
    { cout<<"answer"<<" ";
        cnt++;
        eval(answer);
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        string left_substr = s.substr(0, i);
        string right_substr = s.substr(i + 1);
        string rest = left_substr + right_substr;
        permute(rest, answer + ch);
    }
}

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    time__("dsad")
    {
        while (t--)
        {
            string s;
            cin >> s;
            //  permute(s,"");
            sort(s.begin(), s.end());
            while (next_permutation(s.begin(), s.end()))
            {   cnt++;
                eval(s);
            }

            cout << ans << " "<<cnt<<"\n";
            cnt=0;
            ans = INT_MIN;
        }
    }
}
