#include<bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define LL long long 
#define mod 1000000007
#define FOR(i, j, k) for (int i=j ; i<k ; i++)
 
const long long INF = 1e18;
const long long MAX = 1e5+10;

int main(){
    fastio;
    int t; cin>>t;
    while(t--){
        LL n,k; cin>>n>>k;
        if(k==1) {cout<<(n*n+n)/2<<"\n"; continue;}
        LL i =k-1,ans=0,d=1;
        while(i<=n) {
            ans+=d*(i-i/k);d++;
            i=k*(i+1)-1;
        }ans+=d*(n-i/k)+1;
        cout<<ans<<"\n";
    }
}