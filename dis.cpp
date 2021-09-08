#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
#define LL long long
#define mod 100000000
#define FOR(i, j, k) for (int i = j; i < k; i++)
#define ROF(i, j, k) for (int i = j; i >= k; i--)
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d) for (long blockTime = 0; (blockTime == 0 ? (blockTime = clock()) != 0 : false); debug("%s time : %.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))

const long long INF = 1e18;
const long long MAX = 1e5 + 10;

std::string getDistinctLetterString(std::string s)
{
    // Code here
    vector<int> cnt(30, 0);
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        cnt[s[i] - 'a']++;
    }
    string ans;
    stack<char>st;
    map<char,bool>mp;
    for (int i = 0; i < n; i++)
    {
        int l = s[i] - 'a';
     //   if(st.empty() || st.top()<=s[i]) st.push(s[i]);
        while(!st.empty() && st.top() >= s[i] && cnt[st.top()-'a']>1 && !mp[s[i]]) {
                cnt[st.top()-'a']--;
                mp[st.top()] = false;
                st.pop();
        }
        if(!mp[s[i]])
            st.push(s[i]), mp[s[i]] = true;
        else cnt[l]--;
    }
    while(!st.empty()){
        int l = st.top()-'a';
        if(cnt[l]==1)
            ans+=st.top();
        else cnt[l]--;
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
    fastio;
    int t = 1; //cin>>t;
    while (t--)
    {
        cout << getDistinctLetterString("ababcb");
    }
}
