#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for (auto i=j ; i<k ; i++)

int main() {
    string s; cin>>s;
    map<char,int>m;

    FOR(i,0,s.size()) {
        m[s[i]]++;
    }    
    int ans = 0;
    FOR(i,0,s.size()) {
        if(m[s[i]]==1) {
            ans++; m[s[i]] =0;
        }
    }
    cout<<ans;
}