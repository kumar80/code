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
const long long MAX = 1e5+10;

int main(){
    fastio;
    int t=1;// cin>>t; 
    while(t--){
        int n; cin>>n;
        int arr[n],x[n]; FOR(i,0,n) cin>>arr[i],x[i]=arr[i];
		
 		long long ans1 = 0;
			long long c1 = 0;
		
		for(int i = 0; i < n ; ++i)
		{	c1+=x[i];
			ans1+=abs(c1);
			// ans1 += (LL)abs(x[i]);
			// x[i + 1] += x[i];
		}
		printf("%lld\n", ans1);
    }
}