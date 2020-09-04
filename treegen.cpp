// C++ implementation to generate 
// test-case for the Tree 

#include <bits/stdc++.h> 
using namespace std; 

typedef long long int ll; 
#define fast ios_base::sync_with_stdio(false); 
#define MOD 1000000007 

// Maximum Number Of Nodes 
#define MAXNODE 10; 

// Maximum Number Of testCases 
#define MAXT 10; 

// Maximum weight 
#define MAXWEIGHT 100; 

// Function for the path 
// compression technique 
ll find(ll parent[], ll x) 
{ 
	// If parent found 
	if (parent[x] == x) 
		return x; 

	// Find parent recursively 
	parent[x] = find(parent, parent[x]); 

	// Return the parent node of x 
	return parent[x]; 
} 

// Function to compute the union 
// by rank 
void merge(ll parent[], ll size[], 
		ll x, ll y) 
{ 
	ll r1 = find(parent, x); 
	ll r2 = find(parent, y); 

	if (size[r1] < size[r2]) { 
		parent[r1] = r2; 
		size[r2] += size[r1]; 
	} 
	else { 
		parent[r2] = r1; 
		size[r1] += size[r2]; 
	} 
} 

// Function to generate the 
// test-cases for the tree 
void generate() 
{ 
	ll t=1; 
//	t = 1 + rand() % MAXT; 

	// Number of testcases 
	//cout << t << "\n"; 
	while (t--) { 

		// for 2<=Number of Nodes<=MAXNODE 

		// Randomly generate number of edges 
		ll n = 2 + rand() % MAXNODE; 
		ll i; 
		cout << n << "\n"; 
		ll parent[n + 1]; 
		ll size[n + 1]; 

		// Initialise parent and 
		// size arrays 
		for (i = 1; i <= n; i++) { 
			parent[i] = i; 
			size[i] = 1; 
		} 

		vector<pair<ll, ll> > Edges; 
		vector<ll> weights; 

		// Now We have add N-1 edges 
		for (i = 1; i <= n - 1; i++) { 
			ll x = 1 + rand() % n; 
			ll y = 1 + rand() % n; 

			// Find edges till it does not 
			// forms a cycle 
			while (find(parent, x) 
				== find(parent, y)) { 

				x = 1 + rand() % n; 
				y = 1 + rand() % n; 
			} 

			// Merge the nodes in tree 
			merge(parent, size, x, y); 

			// Store the current edge and weight 
			Edges.push_back(make_pair(x, y)); 
			ll w = 1 + rand() % MAXWEIGHT; 
			weights.push_back(w); 
		} 

		// Print the set of edges 
		// with weight 
		for (i = 0; i < Edges.size(); i++) { 

			cout << Edges[i].first << " "
				<< Edges[i].second; 
			//cout << " " << weights[i]; 
			cout << "\n"; 
		} 
	} 
} 

// Driver Code 
int main() 
{ 
	// Uncomment the below line to store 
	// the test data in a file 
	// freopen ("output.txt", "w", stdout); 

	// For random values every time 
	srand(time(NULL)); 

	fast; 

	generate(); 
} 
