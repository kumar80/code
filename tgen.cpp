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

void swap (int *a, int *b)  
{  
    int temp = *a;  
    *a = *b;  
    *b = temp;  
}  
  
// A utility function to print an array  
void printArray (int arr[], int n)  
{  
    for (int i = 0; i < n; i++)  
        cout << arr[i] << " ";  
    cout << "\n";  
}  
  
// Generating permutation using Heap Algorithm 
void heapPermutation(int a[], int size, int n) 
{ 
    // if size becomes 1 then prints the obtained 
    // permutation 
    if (size == 1) 
    { 
        printArray(a, n); 
        return; 
    } 
  
    for (int i=0; i<size; i++) 
    { 
        heapPermutation(a,size-1,n); 
  
        // if size is odd, swap first and last 
        // element 
        if (size%2==1) 
            swap(a[0], a[size-1]); 
  
        // If size is even, swap ith and last 
        // element 
        else
            swap(a[i], a[size-1]); 
    } 
} 


// A function to generate a random  
// permutation of arr[]  
void randomize (int arr[], int n)  
{  
    // Use a different seed value so that  
    // we don't get same result each time 
    // we run this program  
  //  srand (time(NULL));  
  
    // Start from the last element and swap  
    // one by one. We don't need to run for  
    // the first element that's why i > 0  
    for (int i = n - 1; i > 0; i--)  
    {  
        // Pick a random index from 0 to i  
        int j = rand() % (i + 1);  
  
        // Swap arr[i] with the element  
        // at random index  
        swap(&arr[i], &arr[j]);  
    }  
}  

// Function for the path 
// compression technique 
LL find(LL parent[], LL x) 
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
void merge(LL parent[], LL size[], 
		LL x, LL y) 
{ 
	LL r1 = find(parent, x); 
	LL r2 = find(parent, y); 

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
void generateTree(int MAXNODE, int MAXWEIGHT) 
{ 
		// for 2<=Number of Nodes<=MAXNODE 

		// Randomly generate number of edges 
		LL n = 2 + rand() % MAXNODE; 
		LL i; 
		cout << n << "\n"; 
		LL parent[n + 1]; 
		LL size[n + 1]; 

		// Initialise parent and 
		// size arrays 
		for (i = 1; i <= n; i++) { 
			parent[i] = i; 
			size[i] = 1; 
		} 

		vector<pair<LL, LL> > Edges; 
		vector<LL> weights; 

		// Now We have add N-1 edges 
		for (i = 1; i <= n - 1; i++) { 
			LL x = 1 + rand() % n; 
			LL y = 1 + rand() % n; 

			// Find edges tiLL it does not 
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
			LL w = 1 + rand() % MAXWEIGHT; 
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
// Driver code 
int main(){
	fastio;
 	srand(time(NULL));
	int t = 10;
	cout<<t<<"\n";
	while(t--){
		int n  = 1+rand()%100,k=rand()%n,m=1;
		cout<<n<<" "<<k<<"\n";
		int a[n]; FOR(i,0,n) a[i]=i;
        randomize(a,n);
        printArray(a,n);
	}
	return 0; 
} 
