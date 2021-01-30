#include<bits/stdc++.h>
using namespace std;
 
 int main() {
   string s; cin>>s;
   vector<bool>v(10,false);
   bool ok = true;
   for(int i = 0;i<s.size();i++) {
        int n = s[i] -'0';
        if(n>0 && n<10) v[n] = true;
   }
   for(int i=1;i<10;i++) {
     if(v[i]==false) ok = false;
   }
   if(ok) cout<<"Yes";
   else cout<<"NO";

 }