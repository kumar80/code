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
        int n,m; cin>>n>>m;
        char a[n][m];
        FOR(i,0,n) FOR(j,0,m) cin>>a[i][j];
        FOR(i,0,n) {
            int cnt =0; 
            FOR(j,0,m){
                if(a[i][j]=='.' || a[i][j]=='P') cnt++;
            }
            if(cnt==m) {
                FOR(j,0,m) a[i][j]  = 'P';
            }
        }
        FOR(i,0,m) {
            int cnt =0; 
            FOR(j,0,n){
                if(a[j][i]=='.' || a[j][i] =='P') cnt++;
            }
            if(cnt==n) {
                FOR(j,0,n) a[j][i]  = 'P';
        }
        }
        FOR(i,0,n){
            int cnt = 0;
            FOR(j,0,m){
                if(a[i][j]=='P') cnt++;
            }
            if(cnt==m) continue;
            FOR(j,0,m) {
            if(a[i][j]=='P') continue;
              cout<<a[i][j];
            }
            cout<<"\n";
        }
    }
}
