
#include<bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define LL long long 
#define mod 998244353 
#define FOR(i, j, k) for (int i=j ; i<k ; i++)
#define ROF(i, j, k) for (int i=j ; i>=k ; i--) 
 
const long long INF = 1e18;
const long long MAX = 1e5+10;

typedef  unordered_map<int, unordered_map<int, unordered_map<int, int>>> ThreeLayerMap;

LL maxDeductions(LL a, LL b, LL c, unordered_map<LL, unordered_map<LL, unordered_map<LL, LL>>> &m)
{
    LL positives = 0;
    positives += (a>0) ? 1 : 0;
    positives += (b>0) ? 1 : 0;
    positives += (c>0) ? 1 : 0;

    // TODO: SORT a,b,c such that a >= b >= c
    LL x[3]; x[0]=a;x[1]=b;x[2]=c; 
    sort(x,x+3); a=x[0];b=x[1];c=x[2];
    LL lookup = m[a][b][c];

    if (lookup != -1)
    {
        return lookup;
    }

    if (positives < 2)
    {
        m[a][b][c] = -1;
        return 0;
    }

    LL d1 = 1 + maxDeductions(a-1, b-1, c,m);
    LL d2 = 1 + maxDeductions(a-1, b, c-1,m);
    LL d3 = 1 + maxDeductions(a, b-1, c-1,m);

    LL result;
    if ((d1 >= d2) && (d1 >= d3)) result = d1;
    if (d2 >= d3) result = d2;
    result = d3;

    m[a][b][c] = result;
    return result;
}

int main(){
    fastio;
    LL t; cin>>t;
    while(t--){
    	LL a[3]; cin>>a[0]>>a[1]>>a[2];
    	sort(a,a+3);
        unordered_map<LL, unordered_map<LL, unordered_map<LL, LL>>> ThreeLayerMap;
        cout<<maxDeductions(a[0],a[1],a[2],ThreeLayerMap)<<"\n";
    }      
}
