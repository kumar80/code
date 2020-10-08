// C++ program to find uncommon elements of 
// two sorted arrays 
#include <bits/stdc++.h> 
using namespace std; 


// Driver code 
int main() 
{   int n,m; cin>>n>>m;

	int a1[n]; 
	int a2[m]; map<int,int>m1,m2;
    for(int i=0;i<n;i++) cin>>a1[i],m1[a1[i]]++;
    for(int i=0;i<m;i++) cin>>a2[i],m2[a2[i]]++;

    int ans = 0;
    for(auto i = m1.begin();i!=m1.end();i++){
       if(m2[i->first]==0) ans+=abs(i->second);
        m2[i->first]=0;
    }
    for(auto i = m2.begin();i!=m2.end();i++){
        if(m1[i->first]==0) ans+=i->second;
    }
    cout<<ans;

	return 0; 
} 
