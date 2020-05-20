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
    // int t; cin>>t;
    // while (t--)
    // {
    //     int n; cin>>n;
    //     if(n==1) cout<<-1;
    //     else {
    //         cout<<2;
    //         FOR(i,1,n) cout<<9;
    //     }
    //     cout<<"\n";
    // }
    deque<int>d{1,2,3,4,5,6,7,8,9};
    auto it = d.begin();
    while(!d.empty()){
        if((*it)%2==0){
          cout<<*it<<"#"; d.erase(it); cout<<*it<<"!";
            it++;
        }
        else {
           cout<<*it<<":: ";
           it++;
        }
       // for(auto itt =d.begin();itt!=d.end();itt++) cout<<*itt<<" ";
        cout<<endl;
    }
    
}