                           
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
    int t=1; cin>>t;
    while(t--){
        int n,x; cin>>n>>x; vector<int>a(n);
        int o=0,e=0; 
        
        FOR(i,0,n) {
            cin>>a[i];
            if(a[i]&1) o++;
            else e++;
        }
        bool p  = false;
        FOR(i,1,min(x+1,o+1)) {
            if(i&1 && (x-i)<=e) {p=true; break;}  
        }
        if(p) cout<<"YES";
        else cout<<"NO";
        cout<<"\n";
    }
}
