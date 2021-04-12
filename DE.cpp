#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for (auto i=j ; i<k ; i++)

void f( int t, vector<string>arr){
    int k=0;
    int ans = 0;
    // while(k<t){
    //     k++;
    //     string s=arr[k];
    //     vector<int>v(30,0);
    //     int n = s.size();
        
    //     FOR(i,0,n){
    //         v[s[i]-'a']++;
    //     }
    //     int o=0,e=0;
    //     FOR(i,0,26){
    //         if(v[i]&1) o++;
    //         else e++;
    //     }
    //     if(n&1){
    //         if(o==1|| o==3) ans++;
    //     }
    //     else {
    //         if(o==2) ans++;   
    //     }
    // }
    cout<< ans;
}
int main() {
    int t; cin>>t; vector<string>v(t);
    FOR(i,0,t) cin>>v[i];
    f(t,v);
}