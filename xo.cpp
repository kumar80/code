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
        LL a,b,c; cin>>a>>b>>c;
        if((2*b-a)%c==0 &&  ((2*b-a)/c) )  cout<<"YES";
        else if((2*b-c)%a==0 && ((2*b-c)/a)  ) cout<<"YES";
        else if((a+c)%(2*b)==0 && ((a+c)/(2*b))  ) cout<<"YES";
        else cout<<"NO";
        cout<<"\n";
    }
}

