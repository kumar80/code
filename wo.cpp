// C++ program to find minimum XOR value in an array. 
#include <bits/stdc++.h> 
using namespace std; 
#define INT_SIZE 32 

// A Trie Node 
struct TrieNode { 
	int value; // used in leaf node 
	TrieNode* Child[2]; 
}; 

// Utility function to create a new Trie node 
TrieNode* getNode() 
{ 
	TrieNode* newNode = new TrieNode; 
	newNode->value = 0; 
	newNode->Child[0] = newNode->Child[1] = NULL; 
	return newNode; 
} 

// utility function insert new key in trie 
void insert(TrieNode* root, int key) 
{ 
	TrieNode* temp = root; 

	// start from the most significant bit, insert all 
	// bit of key one-by-one into trie 
	for (int i = INT_SIZE - 1; i >= 0; i--) { 
		// Find current bit in given prefix 
		bool current_bit = (key & (1 << i)); 

		// Add a new Node into trie 
		if (temp->Child[current_bit] == NULL) 
			temp->Child[current_bit] = getNode(); 

		temp = temp->Child[current_bit]; 
	} 

	// store value at leafNode 
	temp->value = key; 
} 

// Returns minimum XOR value of an integer inserted 
// in Trie and given key. 
int minXORUtil(TrieNode* root, int key) 
{ 
	TrieNode* temp = root; 

	for (int i = INT_SIZE - 1; i >= 0; i--) { 
		// Find current bit in given prefix 
		bool current_bit = (key & (1 << i)); 

		// Traversal Trie, look for prefix that has 
		// same bit 
		if (temp->Child[current_bit] != NULL) 
			temp = temp->Child[current_bit]; 

		// if there is no same bit.then looking for 
		// opposite bit 
		else if (temp->Child[1 - current_bit] != NULL) 
			temp = temp->Child[1 - current_bit]; 
	} 

	// return xor value of minimum bit difference value 
	// so we get minimum xor value 
  cout<<temp->value<<" ";
	return key ^ temp->value; 
} 

// Returns minimum xor value of pair in arr[0..n-1] 
int minXOR(int arr[], int n) 
{ 
	int min_xor = INT_MAX; // Initialize result 

	// create a True and insert first element in it 
	TrieNode* root = getNode(); 
	insert(root, arr[0]); 

	// Traverse all array element and find minimum xor 
	// for every element 
	for (int i = 1; i < n; i++) { 
		// Find minimum XOR value of current element with 
		// previous elements inserted in Trie 
		min_xor = min(min_xor, minXORUtil(root, arr[i])); 

		// insert current array value into Trie 
		insert(root, arr[i]); 
	} 
	return min_xor; 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 9, 5, 3 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << minXOR(arr, n) << endl; 
	return 0; 
} 
