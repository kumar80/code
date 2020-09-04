#include<bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define LL long long 
#define mod 1000000007 
#define all(v) v.begin(),v.end()

bool isPalindrome(string s, int i, int j) 
{ 
	int l = i; 
	int h = j; 

	while (h > l) 
	{ 
		if (s[l++] != s[h--]) 
		{ 
			return false; 
		} 
	} 
    return true;
} 

int main() 
{  
    string s; cin>>s; int cnt =0;
    for(int i=0;i<s.size();i++)
        for(int j = i ;j< s.size();j++)
              if(isPalindrome(s,i,j)) cnt++;

        cout<<cnt;
	return 0; 
}
