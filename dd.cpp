#include<bits/stdc++.h>
using namespace std;

int f(int *a, int l, int r, int x){
    int v=INT_MIN; 
    while(l<=r){
        int m = (l+r)/2;
        if(a[m]<=x) {
            v=a[m];
            l=m+1;
        }else r=m-1; 
    }
    return v;
}

int g(int *a, int l, int r, int x){
    int v=INT_MAX; 
    while(l<=r){
        int m = (l+r)/2;
        if(a[m]>=x) {
            v=a[m];
            r=m-1;
        }else l=m+1; 
    }
    return v;
}
int main(){
    int n=8,d=5; //cin>>d>>n;
    int a[n] = {2,1,4,2,3,2,2,6};
   // for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++){
        int p = max(f(a,0,i-1,a[i]+d),f(a,i+1,n-1,a[i]+d));
        int q = min(g(a,0,i-1,a[i]+d),g(a,i+1,n-1,a[i]+d));
      //  cout<<p<<" "<<q<<" "<<a[i]<<"\n";
        if( abs(abs(p-a[i])-d) > abs(abs(q-a[i])-d)){
            v.push_back({q,a[i]});
        }
        else if( abs(abs(p-a[i])-d) < abs(abs(q-a[i])-d)){
            v.push_back({p,a[i]});
        }
        else{
            if(p > q )
                v.push_back({q,a[i]});
            else 
                v.push_back({p,a[i]}); 
        }
      //  cout<<v.back().first<<" "<<v.back().second<<";\n";
    }
    int mn=INT_MAX,ans=INT_MAX;
    for(int i=0;i<n;i++){
        int p = v[i].first;
        int q = v[i].second;
        if(abs(abs(p-q)-d) <= mn) {
            if(abs(abs(p-q)-d) == mn) ans = min(ans,p+q);
            else ans = p+q;
            mn=abs(abs(p-q)-d);
           // cout<<p<<" "<<q<<" "<<ans<<" "<<mn<<"&&\n";
        }
    }
    cout<<ans<<"\n";
}