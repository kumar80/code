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

int main(){
    fastio;
    int t; cin>>t;
    while(t--){
        LL x,n; cin>>x>>n;
        LL o = (n+1)/2;
        LL e = n-o;
        if(x&1) { 
            if(n%4==1) cout<<x+n<<"\n";
            else if(n%4==2) cout<<x-1<<"\n";
            else if(n%4==3) cout<<x-1-n<<"\n";
            else cout<<x<<"\n";
        }
         else  {  
            if(n%4==1) cout<<x-n<<"\n";
            else if(n%4==2) cout<<x+1<<"\n";
            else if(n%4==3) cout<<x+1+n<<"\n";
            else cout<<x<<"\n";
         }
 
    }
}