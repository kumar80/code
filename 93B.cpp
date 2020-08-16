                            
#include<bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define LL long long 
#define mod 1000000007 
#define all(v) v.begin(),v.end()
#define pr(v) pair<v,v>
#define pb push_back
#define FOR(i, j, k) for (auto i=j ; i<k ; i++)
bool prime[10000]; 

void Si(){ 
    memset(prime, true, sizeof(prime));   
    for (int p=2; p*p<10000; p++)     
        if (prime[p] == true)         
            for (int i=p*p; i<10000; i += p) 
                    prime[i] = false; 
} 
int main(){
    fastio;
    int t=1; cin>>t;
    while(t--){
        string s;  cin>>s;
        int a=0,b=0;
        vector<int>o;
        FOR(i,0,s.size()) {
            int j = i;
            while(j<s.size() && s[j]=='1') j++;
            if(j!=i) o.push_back(j-i),i=j-1;
        }
        sort(all(o),greater<int>());
        FOR(i,0,o.size()) {
            if(i%2==0) a+=o[i];
        }
        cout<<a<<"\n";
    }
}
