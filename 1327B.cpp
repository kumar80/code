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
        bool d[MAX]={false},k[MAX]={false};
        FOR(i,1,n+1){
            int x; cin>>x;
            FOR(j,0,x) {int y; cin>>y; 
            if(d[i]) continue; if(!k[y]) {d[i]=true; k[y]=true;}
         }
        }
        
        int x=0,y=0;
        FOR(i,1,n+1) if(!d[i]){x=i; break;}
        FOR(i,1,n+1) if(!k[i]){y=i; break;}
        if(x && y){
            cout<<"IMPROVE"<<"\n";
            cout<<x<<" "<<y; 
        }
        else {
            cout<<"OPTIMAL";
        }
        cout<<"\n";
    }
}