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
   int n; cin>>n;
   vector<int>adj[MAX]; vector<pair<int,int>> v;
   FOR(i,0,n-1)  {int x,y; cin>>x>>y; adj[x].push_back(y); adj[y].push_back(x);v.push_back({x,y});}
   map<pair<int,int>,int> m;
   int k=0,j=n-1;
   FOR(i,1,n+1){
       if(adj[i].size()==1){
           m[{i,adj[i][0]}]=k;
           k++;
       }
       else{
           m[{i,adj[i][0]}]=j;
           j--;
       }
   }
   FOR(i,0,v.size()) cout<<m[{v[i].first, v[i].second}]<<"\n";
}