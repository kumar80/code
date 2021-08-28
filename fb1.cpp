#include<bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define LL long long 
#define mod 1000000007 
#define all(v) v.begin(),v.end()
#define pr(v) pair<v,v>
#define pb push_back
#define FOR(i, j, k) for (auto i=j ; i<k ; i++)
#define ROF(i, j, k) for (auto i=j ; i>=k ; i--) 
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false); debug("%s time : %.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))

const long long INF = 1e18;
const long long MAX = 2e5+10;

bool isVowel(char ch){
    return ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U';
}
int main(){
    fastio;
    int t,T; cin>>t;
    T=1;
    while(t--){
        string s; cin>>s;
        int ans = INT_MAX;
        for(char ch = 'A'; ch<='Z';ch++){
            int res = 0;
            FOR(i,0,s.size()){
                if(ch == s[i]) continue;
                else if(isVowel(s[i])){
                    if(isVowel(ch)) res+=2;
                    else res++;
                }
                else {
                    if(isVowel(ch)) res++;
                    else res+=2;
                }
            }
            ans = min(ans,res);
        }
        cout<<"Case #"<<T++<<": "<<ans<<"\n";
    }
}