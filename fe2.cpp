// C++ program to delete a node from AVL Tree
#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define LL long long 
#define FOR(i, j, k) for (auto i=j ; i<k ; i++)

struct pt{
    LL l,r;
    pt(LL x, LL y){
      l=x; r=y;
    }
    pt(){}
};

struct Node
{
	pt key;
	Node *left;
	Node *right;
	int height;
};

// A utility function to get maximum
// of two integers
int max(int a, int b);

// A utility function to get height
// of the tree
int height(Node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

// A utility function to get maximum
// of two integers
int max(int a, int b)
{
	return (a > b)? a : b;
}

/* Helper function that allocates a
new node with the given key and
NULL left and right pointers. */
Node* newNode(pt key)
{
	Node* node = new Node();
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; // new node is initially
					// added at leaf
	return(node);
}

// A utility function to right
// rotate subtree rooted with y
// See the diagram given above.
Node *rightRotate(Node *y)
{
	Node *x = y->left;
	Node *T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = max(height(y->left),
					height(y->right)) + 1;
	x->height = max(height(x->left),
					height(x->right)) + 1;

	// Return new root
	return x;
}

// A utility function to left
// rotate subtree rooted with x
// See the diagram given above.
Node *leftRotate(Node *x)
{
	Node *y = x->right;
	Node *T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = max(height(x->left),
					height(x->right)) + 1;
	y->height = max(height(y->left),
					height(y->right)) + 1;

	// Return new root
	return y;
}

// Get Balance factor of node N
int getBalance(Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) -
		height(N->right);
}

Node* insert(Node* node, pt key)
{
	/* 1. Perform the normal BST rotation */
	if (node == NULL)
		return(newNode(key));

	if (key.r < node->key.l)
		node->left = insert(node->left, key);
	else if (key.l > node->key.r)
		node->right = insert(node->right, key);
	else // Equal keys not allowed
		return node;

	/* 2. Update height of this ancestor node */
	node->height = 1 + max(height(node->left),
						height(node->right));

	/* 3. Get the balance factor of this
		ancestor node to check whether
		this node became unbalanced */
	int balance = getBalance(node);

	// If this node becomes unbalanced,
	// then there are 4 cases

	// Left Left Case
	if (balance > 1 && key.r < node->left->key.l)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && key.l > node->right->key.r)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && key.l > node->left->key.r)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && key.r < node->right->key.l)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}

/* Given a non-empty binary search tree,
return the node with minimum key value
found in that tree. Note that the entire
tree does not need to be searched. */
Node * minValueNode(Node* node)
{
	Node* current = node;

	/* loop down to find the leftmost leaf */
	while (current->left != NULL)
		current = current->left;

	return current;
}

// Recursive function to delete a node
// with given key from subtree with
// given root. It returns root of the
// modified subtree.
Node* deleteNode(Node* root, pt key)
{
	
	// STEP 1: PERFORM STANDARD BST DELETE
	if (root == NULL)
		return root;

	// If the key to be deleted is smaller
	// than the root's key, then it lies
	// in left subtree
	if ( key.r < root->key.l )
		root->left = deleteNode(root->left, key);

	// If the key to be deleted is greater
	// than the root's key, then it lies
	// in right subtree
	else if( key.l > root->key.r )
		root->right = deleteNode(root->right, key);

	// if key is same as root's key, then
	// This is the node to be deleted
	else
	{
		// node with only one child or no child
		if( (root->left == NULL) ||
			(root->right == NULL) )
		{
			Node *temp = root->left ?
						root->left :
						root->right;

			// No child case
			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else // One child case
			*root = *temp; // Copy the contents of
						// the non-empty child
			free(temp);
		}
		else
		{
			// node with two children: Get the inorder
			// successor (smallest in the right subtree)
			Node* temp = minValueNode(root->right);

			// Copy the inorder successor's
			// data to this node
			root->key = temp->key;

			// Delete the inorder successor
			root->right = deleteNode(root->right,
									temp->key);
		}
	}

	// If the tree had only one node
	// then return
	if (root == NULL)
	return root;

	// STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
	root->height = 1 + max(height(root->left),
						height(root->right));

	// STEP 3: GET THE BALANCE FACTOR OF
	// THIS NODE (to check whether this
	// node became unbalanced)
	int balance = getBalance(root);

	// If this node becomes unbalanced,
	// then there are 4 cases

	// Left Left Case
	if (balance > 1 &&
		getBalance(root->left) >= 0)
		return rightRotate(root);

	// Left Right Case
	if (balance > 1 &&
		getBalance(root->left) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	// Right Right Case
	if (balance < -1 &&
		getBalance(root->right) <= 0)
		return leftRotate(root);

	// Right Left Case
	if (balance < -1 &&
		getBalance(root->right) > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

void search(Node* root, pt &key, LL &d, LL x){
    if(root==NULL) return;
    if(root->key.l<=x && root->key.r>=x){
        d=0; key.l=root->key.l;
        key.r = root->key.r;
    }
    else if(root->key.l> x){
        if(root->key.l-x <d || (root->key.l-x == d && key.l>root->key.r)){
           d = root->key.l-x;
           key.l = root->key.l;
           key.r = root->key.r;
        }
        search(root->left,key,d,x);
    }
    else {
        if(x-root->key.r <d || (x-root->key.r == d && key.l>root->key.r)){
           d = x-root->key.r;
           key.l = root->key.l;
           key.r = root->key.r;
        }
        search(root->right,key,d,x);
    }
}
// Driver Code
int main()
{
 fastio;
    int t=1; cin>>t; int T=1;
   // auto start = high_resolution_clock::now();
    while(t--){
      Node* root = NULL;
      int n,m; cin>>n>>m;
      pt v[n];
      LL vv[m];
      LL ans[m];
      FOR(i,0,n){
          cin>>v[i].l>>v[i].r;
      }
      FOR(i,0,m) cin>>vv[i];
      FOR(i,0,n){
        root=insert(root, pt(v[i].l, v[i].r));
      }
      FOR(i,0,m){
        LL x=vv[i];
        LL d = 1e18;
        pt p = pt(INT_MAX, INT_MAX);
        search(root,p,d,x);
        root = deleteNode(root, pt(p.l,p.r));
        LL k=x-d>=p.l && x-d<=p.r?x-d:x+d;

        ans[i] = k;        
        if(p.l == p.r) continue;
        if(p.l == k)
          root = insert(root,pt(k+1,p.r));
        else if(p.r==k)
          root = insert(root,pt(p.l,k-1));
        else {
          root = insert(root,pt(p.l,k-1));
          root = insert(root,pt(k+1,p.r));
        }
      }
      printf("Case #%d: ",T++);
      for(int i =0;i<m;i++) printf("%lld ",ans[i]); 
      printf("\n");
    }
}

