#include<bits/stdc++.h>
using namespace std;
 
 int main() {
     int n,k; cin>>n>>k;
     vector<int>a(2*n+1),p(2*n+1,0),s(2*n+2,0); 
     for(int i=1;i<=n;i++){
         cin>>a[i];
     }
     for(int i=n+1;i<2*n+1;i++){
         a[i]=a[i-n];
     }
     for(int i=1;i<2*n+1;i++) {
         p[i]=a[i]+p[i-1];
     }
    for(int i=1;i<n+1;i++){
        if(p[i+k]-p[i]>=0) cout<<p[i+k]-p[i]<<" ";
        else cout<<p[i-1]-p[i-k-1]<<" ";
    }

 }