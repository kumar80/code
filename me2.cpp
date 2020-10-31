#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
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
int main()
{
    fastio;
    int t = 1; // cin>>t;
    while (t--)
    {
        int n,m; string s1, s2;
        cin>>n>>s1>>m>>s2;
        int len = s1.size();
        set<int>b[n+100],l[m+100];
       int j=1,k=0;
        FOR(i,0,len){
            if(s1[i]==',') {
                b[j].insert(k); j++;k=0;
            }else if(s1[i]=='&') {
                b[j].insert(k); k=0;
            }else k=k*10+s1[i]-'0';
        }  b[j].insert(k); 
        j=1,k=0; len=s2.size();
        FOR(i,0,len){
            if(s2[i]==',') {
                l[j].insert(k); j++;k=0;
            }else if(s2[i]=='&') {
                l[j].insert(k); k=0;
            }else k=k*10+s2[i]-'0';
        }  l[j].insert(k);
        int ans = 0;
        while (1)
        {
            set<int> B, P;
            FOR(i, 1, n+1)
            {
                if (b[i].size() > 0)
                {
                    if (B.find(i) == B.end() && P.find(*b[i].begin()) == P.end())
                    {
                        B.insert(i), P.insert(*b[i].begin());
                        auto it = l[*b[i].begin()].find(i);
                        if (it != l[*b[i].begin()].end())
                            l[*b[i].begin()].erase(it);
                        b[i].erase(b[i].begin());
                    }
                }
            }
            FOR(i, 1, m+1)
            {
                if (l[i].size() > 0)
                {
                    if (P.find(i) == P.end() && B.find(*l[i].begin()) == B.end())
                    {
                        P.insert(i), B.insert(*l[i].begin());
                        auto it = b[*l[i].begin()].find(i);
                        if (it != b[*l[i].begin()].end())
                            b[*l[i].begin()].erase(it);
                        l[i].erase(l[i].begin());
                    }
                }
            }
            //  cout<<"\n";
            if (B.size() > 0 && P.size() > 0)
                ans++;
            else
                break;
        }

        cout << ans;
    }
    }
