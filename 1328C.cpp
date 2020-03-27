//https://codeforces.com/contest/1328/problem/C
#include<bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define LL long long 
#define mod 998244353 
#define FOR(i, j, k) for (int i=j ; i<k ; i++)
#define ROF(i, j, k) for (int i=j ; i>=k ; i--) 
 
const long long INF = 1e18;
const long long MAX = 1e5+10;

int main(){
    fastio;
    int t; cin>>t;
    while (t--)
    {
        int n; string s; cin>>n; cin>>s;
        int m = 1; string s1="1",s2="1"; 
        for(int i=1;i<n;i++){
            if(s[i]=='0'){
                    s1+='0';
                    s2+='0';
            }
            if(s[i]=='1'){   
                if(m==1) {
                    m=0;s1+='1';s2+='0';
                    }
                else {
                    s1+='0';s2+='1';
                 }
            }
            if(s[i]=='2'){
                if(m==1){
                    s1+='1';
                    s2+='1';
                }else {
                    s1+='0';s2+='2';
                }
            }
        }
    
        cout<<s1<<"\n"<<s2<<"\n";
    }

}