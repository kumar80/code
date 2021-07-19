/* A O(n) program for construction
of BST from preorder traversal */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
class node {
public:
	int data;
	node* left;
	node* right;
};

// A utility function to create a node
node* newNode(int data)
{
	node* temp = new node();

	temp->data = data;
	temp->left = temp->right = NULL;

	return temp;
}

// A recursive function to construct
// BST from pre[]. preIndex is used
// to keep track of index in pre[].
node* constructTreeUtil(int pre[], int* preIndex, int key,
						int min, int max, int size)
{
	// Base case
	if (*preIndex >= size)
		return NULL;

	node* root = NULL;

	// If current element of pre[] is in range, then
	// only it is part of current subtree
	if (key > min && key < max) {
		// Allocate memory for root of this
		// subtree and increment *preIndex
		root = newNode(key);
		*preIndex = *preIndex + 1;

		if (*preIndex < size) {
			// Construct the subtree under root
			// All nodes which are in range
			// {min .. key} will go in left
			// subtree, and first such node
			// will be root of left subtree.
			root->left = constructTreeUtil(pre, preIndex,
										pre[*preIndex],
										min, key, size);
		}
		if (*preIndex < size) {
			// All nodes which are in range
			// {key..max} will go in right
			// subtree, and first such node
			// will be root of right subtree.
			root->right = constructTreeUtil(pre, preIndex,
											pre[*preIndex],
											key, max, size);
		}
	}

	return root;
}

// The main function to construct BST
// from given preorder traversal.
// This function mainly uses constructTreeUtil()
node* constructTree(int pre[], int size)
{
	int preIndex = 0;
	return constructTreeUtil(pre, &preIndex, pre[0],
							INT_MIN, INT_MAX, size);
}

vector<int> parseArray(string s){
    int i=1; 
    vector<int>v;
    while(i<s.size()){
        int n=0;
        while( s[i]!=',' && s[i]!=']'  ){
            n = n*10 + s[i]-'0';
            i++;
        }
        v.push_back(n);
        i++;i++;
    }
    
    return v;
}

int parseInt(string s){
    int n=0,i=0;
    while(i<s.size()){
        n = n*10 + s[i]-'0';
        i++;
    }
    return n;
}

node *lca(node* root, int n1, int n2)
{
    if (root == NULL) return NULL;
  
    // If both n1 and n2 are smaller than root, then LCA lies in left
    if (root->data > n1 && root->data > n2)
        return lca(root->left, n1, n2);
  
    // If both n1 and n2 are greater than root, then LCA lies in right
    if (root->data < n1 && root->data < n2)
        return lca(root->right, n1, n2);
  
    return root;
}

string BinaryChallenge(string s[], int arrLength) {
  
  // code goes here  
    vector<int>v = parseArray(s[0]);
	int pre[v.size()];
	for(int i=0;i<v.size();i++) pre[i]=v[i];
	int size = sizeof(pre) / sizeof(pre[0]);
  //  for(auto i : v) cout<<i<<" ";
	node* root = constructTree(pre, size);
    node* p = lca(root, parseInt(s[1]), parseInt(s[2]));
    string ans = to_string(p->data);
    return ans;
}

int main()
{
    string s[] = {"[3, 2, 1, 12, 4, 5, 13]", "5", "13"};
    cout<<BinaryChallenge(s,2);
	return 0;
}

