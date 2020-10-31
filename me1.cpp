                            
#include<bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define LL long long 
#define mod 1000000007 
#define all(v) v.begin(),v.end()
#define FOR(i, j, k) for (auto i=j ; i<k ; i++)

int main(){
    fastio;
    int t=1; //cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        double p[n],profit[n],loss[n];
        FOR(i,0,n) cin>>p[i];
        FOR(i,0,n) cin>>profit[i];
        FOR(i,0,n) cin>>loss[i];
        vector<double> c(n);
        FOR(i,0,n) c[i]=profit[i]*p[i] -(1-p[i])*loss[i];
        sort(all(c),greater<double>());
        double ans=0;
        FOR(i,0,min(m,n)){
            if(c[i]>0) ans+=c[i];
        }
        cout<<fixed<<setprecision(2)<<ans;
    }
}
  