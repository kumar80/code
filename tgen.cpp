// CPP Program to generate random alphabets 
#include <bits/stdc++.h> 
using namespace std; 

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
{ 
srand(time(NULL)); 
int t=100;
while(t--){
int n = rand()%25; 
cout << printRandomString(n)<<"\n"; 
}
return 0; 
} 
