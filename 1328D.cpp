//https://codeforces.com/contest/1328/problem/D
#include<bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define LL long long 
#define mod 998244353 
#define FOR(i, j, k) for (int i=j ; i<k ; i++)
#define ROF(i, j, k) for (int i=j ; i>=k ; i--) 
 
const long long INF = 1e18;
const long long MAX = 1e5+10;
int col[2*MAX]={0};
vector<int>adj[MAX];
int main(){
    fastio;
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>a(n+1); cin>>a[0];
        FOR(i,1,n) { cin>>a[i]; adj[a[i-1]].push_back(a[i]); } a[n]=a[0];
        vector<int>temp = a;
        auto it = unique(temp.begin(),temp.end());
        temp.resize(distance(temp.begin(),it));
        int c=1;col[temp[0]]=1;
        FOR(i,1,temp.size()) {
            if(col[temp[i]]==0){
                
            }
        }
        cout<<c<<"\n";
        FOR(i,0,n) cout<<col[a[i]]<<" ";
        cout<<"\n"; 
        FOR(i,0,temp.size()) {adj[temp[i]].clear();col[a[i]]=0;}
    }
}