#include<bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define LL long long 
#define mod 1000000007 
#define FOR(i, j, k) for (int i=j ; i<k ; i++)
#define ROF(i, j, k) for (int i=j ; i>=k ; i--) 
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false); debug("%s time : %.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))

const long long INF = 1e18;
const long long MAX = 1e6+10;
 
int main(){
    fastio;
    int t=1; //cin>>t;
    while(t--){
        int n; cin>>n;
        LL a[n]; FOR(i,0,n) cin>>a[i];
        LL s=1,c=1;
        FOR(i,0,n){
            c*=a[i];
            s= c>s?c:s;
            if(c==0) c=1;
        }
        c=1;
        ROF(i,n-1,0){
            c*=a[i];
            s= c>s?c:s;
            if(c==0) c=1;
        }
        cout<<s;
    }
}
