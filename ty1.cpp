#include<bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define LL long long 
#define mod 998244353 
#define FOR(i, j, k) for (int i=j ; i<k ; i++)
#define ROF(i, j, k) for (int i=j ; i>=k ; i--) 
 
const long long INF = 1e18;
const long long MAX = 1e5+10;


int main(){
    fastio;
    int t=1;// cin>>t;
    while(t--){
        int n; cin>>n;
        int ans = 0;
        for(int i=0;i<n;i++) {
            int x; cin>>x;
            int cnt = 0;
            while(x%2==0) x/=2,cnt++;
            ans+=cnt;
        }
        cout<<ans;
    }
}
