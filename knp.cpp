#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for (auto i=j ; i<k ; i++)

int f(int W, vector<int>wt, vector<int>val, int n) 
{ 
    int i, w; 
    int K[n + 1][W + 1]; 
  
    for (i = 0; i <= n; i++)  
    { 
        for (w = 0; w <= W; w++)  
        { 
            if (i == 0 || w == 0) 
                K[i][w] = 0; 
            else if (wt[i - 1] <= w) 
                K[i][w] = max(val[i - 1] 
                          + K[i - 1][w - wt[i - 1]], 
                          K[i - 1][w]); 
            else
                K[i][w] = K[i - 1][w]; 
        } 
    } 
  
    return K[n][W]; 
} 

int main() {
    int n; cin>>n; vector<int>iv(n),a(n);
    FOR(i,0,n) cin>>iv[i];
    FOR(i,0,n) cin>>a[i],a[i]*=2;
    int p; cin>>p;
    cout<<f(p,a,iv,n);
}