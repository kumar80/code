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
    vector<vector<int>>v(k+1,vector<int>(2,0));
    FOR(i,0,k){
        int x,y; cin>>x>>y;
        s.push_back({x,y});
    }
    FOR(i,0,k){
        int x,y; cin>>x>>y;
         v[i][0]+=x-s[i].first;
         v[i][1]+=y-s[i].second;
    }
    string p="";
    
}