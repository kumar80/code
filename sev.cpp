#include <bits/stdc++.h>
using namespace std;
int f(string s, string &a){
    int cnt = 0;
    for(int i = 0;i<s.size();i++)
      {
          if(s[i]!=a[i]) cnt++,a[i]=s[i];
      }
    return cnt;
}
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<string>v = {"1111110","0110000", "1101101", "1111001", 
                    "0110011", "1011011", "0011111", "1110000", "1111111", "1110011" };
               
        string s; cin>>s;
        string a = "0000000";
        int ans = 0;
        for(int i = 0; i<n;i++){
           ans+=f(v[s[i]-'0'],a);
        }
        cout<<ans<<"\n";
    }
}