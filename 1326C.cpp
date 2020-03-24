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
    int n,k; cin>>n>>k;
    int a[n],b[2*MAX]; FOR(i,0,n) {cin>>a[i];b[a[i]]=i;}
    LL sum=0,temp=n; FOR(i,0,k) {sum+=temp; temp--;}
    temp=n;vector<int>v;
    FOR(i,0,k) {v.push_back(b[temp]); temp--;}
    LL p=1;
    sort(v.begin(),v.end());
    FOR(i,0,k-1) {
        temp = v[i+1]-v[i];
        p=(p*temp)%mod;
    }
    cout<<sum<<" "<<p;
}