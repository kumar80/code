//https://codeforces.com/contest/1323/problem/B
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define LL long long 
#define ar32(x) array<int, x> 
#define ar64(x) array<LL, x>
// Infinity xP
const int oo = 1e9 + 5;
// const int MOD = 1e9 + 7;
const LL ooll = 1e18;
// const int MOD = 998244353;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

int v[N], w[N], xwin[N], ywin[N];
void solve() {
    int n, m, k, i, j;
    cin >> n >> m >> k;
    for (i=0;i<n;i++) cin >> v[i];
    for (i=0;i<m;i++) cin >> w[i];
    for (i=0;i<=n;i++) xwin[i] = 0;
    for (i=0;i<=m;i++) ywin[i] = 0;

    j = -1;
    for (i=0;i<n;i++) {
        j = max(j, i);
        while(j < n && v[j] == 1) j++;
        int len = j - i;
        xwin[1]++; xwin[len+1]--;
    }

    j = -1;
    for (i=0;i<m;i++) {
        j = max(j, i);
        while(j < m && w[j] == 1) j++;
        int len = j - i;
        ywin[1]++; ywin[len+1]--;
    }
    
    for (i=1;i<=n;i++) {xwin[i] += xwin[i-1]; cout<<xwin[i]<<" ";} cout<<endl;
    for (i=1;i<=m;i++) {ywin[i] += ywin[i-1];cout<<ywin[i]<<" ";}

    LL ans = 0;
    for (i=1;i<=n;i++) if (k % i == 0) {
        int j = k / i;
        if (j <= m) {
            ans += xwin[i] * 1LL * ywin[j];
    
        }
    }
    cout << ans << '\n';
}
 
int main() {
    FASTIO;
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}