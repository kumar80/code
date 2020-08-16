                         
#include<bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define LL long long 
#define mod 1000000007 
#define all(v) v.begin(),v.end()
#define pr(v) pair<v,v>
#define pb push_back
#define FOR(i, j, k) for (auto i=j ; i<k ; i++)


bool prime[10000]; 

void Si(){ 
    memset(prime, true, sizeof(prime));   
    for (int p=2; p*p<10000; p++)     
        if (prime[p] == true)         
            for (int i=p*p; i<10000; i += p) 
                    prime[i] = false; 
} 

int main(){
    fastio;
    int t=1; cin>>t;
    while(t--){
        int n; cin>>n; vector<pr(int)>a(n); FOR(i,0,n) cin>>a[i].first,a[i].second=i+1;
        sort(all(a));
        int r[3];
        bool pos = false;
        
            if( a[0].first+a[n-1].first <= a[1].first || a[0].first+ a[1].first <= a[n-1].first || 
            a[1].first+a[n-1].first<=a[0].first ) {
                pos = true;
                r[0]=a[0].second,r[1]=a[1].second,r[2]=a[n-1].second;
                
            }
        
        if(pos) {
            sort(r,r+3);
            cout<<r[0]<<" "<<r[1]<<" "<<r[2]<<"\n";
        }else cout<<-1<<"\n";
    }
}
