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
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;
        bool ok = false;
        FOR(i,0,n){
            int a=0,b=0;
            FOR(j,i,n){
                if(s[j]=='a') a++;
                else b++;
                if(a==b) {
                    cout<<i+1<<" "<<j+1<<"\n";
                    ok = true;
                    break;
                }
            }
            if(ok) break;
        }
        if(!ok) cout<<-1<<" "<<-1<<"\n";
    }
}