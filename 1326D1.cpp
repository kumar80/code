#include<bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define LL long long 
#define mod 998244353 
#define FOR(i, j, k) for (int i=j ; i<k ; i++)
#define ROF(i, j, k) for (int i=j ; i>=k ; i--) 
 
const long long INF = 1e18;
const long long MAX = 1e5+10;

void lp(vector<int> &v, int n, string s){
    int i=0,j=1; v[i]=0;
    while(j<n){
        if(s[i]==s[j]){
            v[j]=++i;
            j++;
        }
        else {
            if(i!=0){
                i = v[i-1];
            }
            else {
                v[j]=0;
                j++;
            }
        }
    }  
}
int main(){
    fastio;
    int t; cin>>t;
    while(t--){
        string s,p; cin>>s; 
        int i=0,n=s.size();
        while(i<=n/2 && s[i]==s[n-i-1]) i++;
        if(n-2*i>0) p= s.substr(i,n-2*i);
        else {
            cout<<s<<"\n";
            continue;
        }  
        string rv = p; 
        reverse(rv.begin(),rv.end());
        string s1 = p+'@'+rv,s2=rv+'@'+p;  
        n=s1.size();
        vector<int>v1(n),v2(n);
        lp(v1,n,s1);
        lp(v2,n,s2);
        int m1=v1[n-1],m2=v2[n-1];
        //cout<<m1<<" "<<m2<<" "<<s1<<" ";
        if(i==0 && m1==0 && m2==0) cout<<s[0];
        else if(m1>=m2){
            FOR(j,0,i) cout<<s[j];
            FOR(j,0,m1) cout<<s1[j];
            ROF(j,i-1,0) cout<<s[j];
        } else {
            FOR(j,0,i) cout<<s[j];
            FOR(j,0,m2) cout<<s2[j];
            ROF(j,i-1,0) cout<<s[j];
        }
        cout<<"\n";
    }
}