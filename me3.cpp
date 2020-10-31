                             
#include<bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define FOR(i, j, k) for (auto i=j ; i<k ; i++)

int main(){
    fastio;
    int t=1;// cin>>t;
    while(t--){
        string s;
        getline(cin, s); 
        s.erase(remove(s.begin(), s.end(), ' '), s.end()); 
        int n =s.size(); //cout<<n;
        int r= floor(sqrt(n)),c=ceil(sqrt(n));
        if(r*c<n) r=max(r,c),c=max(r,c);
        FOR(i,0,c){
            int cnt=0;
            for(int j=i;j<n && cnt<r;j+=c){
                cnt++; cout<<s[j];
            } cout<<" ";
        } 
    }
}
