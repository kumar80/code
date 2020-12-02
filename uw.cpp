
#include <bits/stdc++.h> 

using namespace std;

int main(){
    int n; cin>>n;
    int a[n]; 
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    if(n<2) cout<<"Invalid Input";
    else {
        bool ok = true;
        for(int i=0;i<n;i++){
            if(a[i]!=a[0]) ok = false;
        }
        if(ok) cout<<"Equal";
        else cout<<a[0]<<" "<<a[1];
    }
}