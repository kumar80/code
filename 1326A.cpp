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
    while (t--)
    {
        int n; cin>>n;
        if(n==1) cout<<-1;
        else {
            cout<<2;
            FOR(i,1,n) cout<<9;
        }
        cout<<"\n";
    }
    
}