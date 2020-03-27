//https://codeforces.com/contest/1328/problem/B
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
        int n,k; cin>>n>>k;
        string s;
        FOR(i,0,n) s+='a';
        int i=1;
        while(i<n){
        
            if(i<=k) k-=i;
            else break;
            i++;
        }

        if(k!=0) i++;
        else k=i-1;
        s[n-i]='b';
        s[n-k]='b';
        cout<<s<<"\n";        
    }
}   