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
    int n,m,k; cin>>n>>m>>k;
    vector<pair<int,int>>s;
    FOR(i,0,k){
        int x,y; cin>>x>>y;
        s.push_back({x,y});
    }
      string p="";
    p.append(n-1,'L'); p.append(m-1,'U');
    p.append(m-1,'R');
    FOR(i,1,n){    
        if(i&1){
           p+='D';
           p.append(m-1,'L');
        }
        else{
            p+='D';
            p.append(m-1,'R');
        }
    }
    cout<<p; 
    
}