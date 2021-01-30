#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for (auto i=j ; i<k ; i++)

bool check(int i,int j, int n, int m){
    if(i<0 || j<0 || i>=n || j>=m) 
        return false;
    return true;
}

int f(int n, int m,vector<vector<int>>&b,int p){
    int dp[n][m];
    FOR(i,0,n) FOR(j,0,m) dp[i][j] = 0;
    dp[0][p]=b[0][p];
    FOR(i,1,n)
        FOR(j,0,m) {
            int ul=0,u=0,ur=0;
            if(check(i-1,j-1,n,m)) ul= dp[i-1][j-1];
            if(check(i-1,j,n,m)) u = dp[i-1][j];
            if(check(i-1,j+1,n,m)) ur = dp[i-1][j+1];
            dp[i][j] = max({ul,u,ur});
            if(dp[i][j]>0) dp[i][j]+=b[i][j];
        }
    int mx  = 0;
    FOR(i,0,m) mx = max(mx,dp[n-1][i]);
    return mx;
}
int maxPathsum(vector<vector<int>>&b,int p, int q){
    int n = b.size(),m=b[0].size();
    int val1  = f(n,m,b,p);
    int l=0,r=n-1;

    while(l<r){
        FOR(i,0,m) swap(b[l][i],b[r][i]);
        l++;r--;
    }
    int val2  = f(n,m,b,q);

    return max(val1,val2);
}
int main() {
    int n,m; cin>>n>>m;
    vector<vector<int>>b(n,vector<int>(m));
    FOR(i,0,n) FOR(j,0,m) cin>>b[i][j];
    int p,q; cin>>p>>q;
    cout<<maxPathsum(b,p,q);
}