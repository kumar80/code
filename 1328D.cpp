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
        int n; cin>>n; int a[n+1]; set<int>s;
        FOR(i,0,n) {cin>>a[i];s.insert(a[i]);} a[n]=a[0];
        if(s.size()==1){
            cout<<1<<"\n";
            FOR(i,0,n) cout<<1<<" ";
        }
       else if(n%2==0){
            cout<<2<<"\n";
            FOR(i,0,n/2) cout<<1<<" "<<2<<" ";
        }
       else if(n & 1){
            bool x =true;int j=-1;
            FOR(i,1,n+1) if(a[i]==a[i-1]){ x=false; j=i-1; break; }     // cout<<j<<"S";     
            if(x) {
                cout<<3<<"\n";
                FOR(i,0,n/2) cout<<1<<" "<<2<<" ";
                cout<<3;
                }
            else {
                cout<<2<<"\n";
                FOR(i,0,j) if(i%2==0) cout<<1<<" "; else cout<<2<<" ";
                if(j%2) {
                    cout<<2<<" ";
                FOR(i,j+1,n) if(i%2==0) cout<<2<<" "; else cout<<1<<" ";
                    }
                else {
                    cout<<1<<" ";
                FOR(i,j+1,n) if(i%2==0) cout<<2<<" "; else cout<<1<<" ";
                    }
            }

        }   
        cout<<"\n";
    }
}