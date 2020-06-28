                       
#include<bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

#define FOR(i, j, k) for (int i=j ; i<k ; i++)
#define ROF(i, j, k) for (int i=j ; i>=k ; i--) 


int main(){
    fastio;
    int t=1; cin>>t;
    while(t--){
        int n,x,y; cin>>x>>y>>n;
        if((n/x)*x+y<=n) cout<<(n/x)*x+y;
        else cout<<((n/x)-1)*x+y;
        cout<<"\n";
    }
}
