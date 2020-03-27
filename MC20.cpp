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
    LL n; cin>>n; set<pair<int,int>>s;
    LL ctr=0,x,y;
    FOR(i,0,10){
        cin>>x;
        vector<LL>c;
        FOR(j,1,10){
            cin>>y; 
            if(s.find({x,y})!=s.end() || s.find({y,x})!=s.end())
                ctr++;
        }        
    }
    n= (n*(n-1))/2;
    cout<<n-ctr;
}