// CPP Program to generate random alphabets 
#include<bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define LL long long 
#define mod 998244353 
#define FOR(i, j, k) for (int i=j ; i<k ; i++)
#define ROF(i, j, k) for (int i=j ; i>=k ; i--) 
 
const long long INF = 1e18;

const int MAX = 26; 

// Returns a string of random alphabets of 
// length n. 
string printRandomString(int n) 
{ 
	char alphabet[MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 
						'h', 'i', 'j', 'k', 'l', 'm', 'n', 
						'o', 'p', 'q', 'r', 's', 't', 'u', 
						'v', 'w', 'x', 'y', 'z' }; 

	string res = ""; 
	for (int i = 0; i < n; i++) 
		res = res + alphabet[rand() % MAX]; 
	
	return res; 
} 

// Driver code 
int main() 
{ 	int t = 1 + rand()%50;
	while(t--){
	int n  = 2 + rand()%5;
	cout<<n<<"\n";
	FOR(i,0,n) cout<<1+rand()%120<<" ";
	cout<<"\n\n";
	}
return 0; 
} 
