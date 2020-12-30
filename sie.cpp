#include<bits/stdc++.h>
using namespace std;
#define LL long long 

int main() {
    int t; cin>>t;
    while(t--){
        LL x; cin>>x;
        LL rt = sqrt(x);
        if(rt*rt==x) {
            cout<<x+1<<"\n";
        }else {
            LL nn = floor(sqrt(x)) + 1; 
            cout<<nn*nn<<"\n";
        }
    }
}