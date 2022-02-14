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
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n];
        vector<int>v(n+1,0);
        FOR(i,0,n) {
            cin>>a[i];
            while(a[i]>n) a[i]/=2;
            v[a[i]]++;
        }
        sort(a,a+n);
        ROF(i,n,1){
            while(v[i]>1){
                v[i]--;
                v[i/2]++;
            }
        }
        bool ok = true;
        FOR(i,1,n+1) 
            if(v[i]==0) ok =false;

        if(ok) cout<<"Yes";
        else cout<<"No";
        cout<<"\n";
    }
}