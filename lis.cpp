#include<bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define LL long long 
#define mod 998244353 
#define FOR(i, j, k) for (int i=j ; i<k ; i++)
#define ROF(i, j, k) for (int i=j ; i>=k ; i--) 
 
const long long INF = 1e18;
const long long MAX = 1e5+10;
 
int main() {
    int n; cin>>n; vector<int>v(n);
    vector<int>d;
    for (int i = 0; i < n; i++) cin>>v[i];
    for (int i = 0; i < n; i++) {
        int x = v[i];
        vector<int>::iterator it = upper_bound(d.begin(), d.end(), x);
        if (it == d.end()) d.push_back(x);
        else *it = x;
    }
    
    cout<< d.size()<<" ";
    FOR(i,0,d.size()) cout<<d[i]<<" ";
    
    // vector<int> tail(v.size(), 0); 
	// int length = 1;

	// tail[0] = v[0]; 
	
	// for (int i = 1; i < v.size(); i++) { 
			 
	// 	auto b = tail.begin(), e = tail.begin() + length; 
	// 	auto it = lower_bound(b, e, v[i]); 
			
	// 	if (it == tail.begin() + length) 
	// 	tail[length++] = v[i]; 
	// 	else
	// 	*it = v[i]; 
	// } 
	// int lis = length; 
    // cout<<d.size()<<" "<<lis;

    return 0;
}