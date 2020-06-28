                             
#include<bits/stdc++.h>
using namespace std;
 
#define LL long long 
#define mod 1000000007 
#define FOR(i, j, k) for (int i=j ; i<k ; i++)
#define ROF(i, j, k) for (int i=j ; i>=k ; i--) 

int main(){
     ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1; cin>>t;
    while(t--){
       int n ;cin>>n; string s;cin>>s; 
        stack<char>st;
        FOR(i,0,n){
            if(st.empty() || s[i]=='(') st.push(s[i]);
            else if(st.top()=='(') st.pop();
            else st.push(s[i]);
        }
        cout<<st.size()/2<<"\n";
    }
}
