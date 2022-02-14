#include<bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define LL long long 
#define mod 1000000007
 
vector<int> f(vector<int> const &input)
{
    int n = input.size();
    vector<int> result(n, -1);
     stack<int> s;
     for (int i = 0; i < n; i++)
    {
        while (!s.empty() && input[s.top()] <= input[i])
        {
            result[s.top()] = i;
            s.pop();
        }
 
        s.push(i);
    }
 
    return result;
}
 
vector<int>  p(vector<int> const &arr)
{   int n  = arr.size();
    stack<int> s;
    s.push(0);
    vector<int> result(n, -1);
 
    for (int i = 1; i < n; i++) {
 
        while (s.empty() == false && arr[s.top()] <= arr[i])
            s.pop();
 
        s.empty() ? result[i]=-1 : result[i] = s.top() ;
 
        s.push(i);
    }
        return result;
}
 
int main(){
    fastio;
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        vector<int>r=f(v);
        vector<int>l=p(v);
        LL ans = 0,j=-1;
        for(int i=0;i<n;i++) {
            LL d1=i-l[i]-1,d2=r[i]-i-1;
            if(l[i]==-1) d1=i;
            if(r[i]==-1) d2=n-i-1;
            d1+=d2;
            LL res  = (((i+1)*d1)%mod + mod)%mod;
            if(res>=ans) j=i+1,ans=res;
                  //cout<<l[i]<<" "<<r[i]<<" "<<ans<<" ;";
        }
        cout<<j<<"\n";
    }
}