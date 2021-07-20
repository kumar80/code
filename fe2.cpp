#include <bits/stdc++.h>

#define SPACE 10
#define fastio                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0)
#define LL unsigned long long
#define FOR(i, j, k) for (auto i = j; i < k; i++)

using namespace std;
bool fr = false;
struct pt
{
  LL l, r;
  pt(LL x, LL y)
  {
    l = x;
    r = y;
    //cout << l << "****" << x << "\n";
  }
  pt() {}
};

class TreeNode
{
public:
  pt key;
  TreeNode *left;
  TreeNode *right;

  TreeNode()
  {
    key = pt();
    left = NULL;
    right = NULL;
  }
  TreeNode(pt p)
  {
    key = p;
    left = NULL;
    right = NULL;
  }
};

class AVLTree
{
public:
  TreeNode *root;
  AVLTree()
  {
    root = NULL;
  }
  bool isTreeEmpty()
  {
    if (root == NULL)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  // Get Height
  int height(TreeNode *r)
  {
    if (r == NULL)
      return -1;
    else
    {
      /* compute the height of each subtree */
      int lheight = height(r->left);
      int rheight = height(r->right);

      /* use the larger one */
      if (lheight > rheight)
        return (lheight + 1);
      else
        return (rheight + 1);
    }
  }

  // Get Balance factor of node N
  int getBalanceFactor(TreeNode *n)
  {
    if (n == NULL)
      return -1;
    return height(n->left) - height(n->right);
  }

  TreeNode *rightRotate(TreeNode *y)
  {
    TreeNode *x = y->left;
    TreeNode *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    return x;
  }

  TreeNode *leftRotate(TreeNode *x)
  {
    TreeNode *y = x->right;
    TreeNode *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    return y;
  }

  TreeNode *insert(TreeNode *r, TreeNode *new_node, bool &ok)
  {
    if (r == NULL)
    {
      r = new_node;
      //cout << "key inserted successfully" << endl;
      return r;
    }

    if (new_node->key.r < r->key.l)
    {
      r->left = insert(r->left, new_node, ok);
    }
    else if (new_node->key.l > r->key.r)
    {
      r->right = insert(r->right, new_node, ok);
    }
    else
    {
      ok = false;

      //cout << "No duplicate keys allowed!" << fr << " " << new_node->key.l << " " << new_node->key.r << endl;
      return r;
    }
    if (!ok)
      return r;
    int bf = getBalanceFactor(r);
    // Left Left Case
    if (bf > 1 && new_node->key.r < r->left->key.l)
      return rightRotate(r);

    // Right Right Case
    if (bf < -1 && new_node->key.l > r->right->key.r)
      return leftRotate(r);

    // Left Right Case
    if (bf > 1 && new_node->key.l > r->left->key.r)
    {
      r->left = leftRotate(r->left);
      return rightRotate(r);
    }

    // Right Left Case
    if (bf < -1 && new_node->key.r < r->right->key.l)
    {
      r->right = rightRotate(r->right);
      return leftRotate(r);
    }

    /* return the (unchanged) node pointer */
    return r;
  }

  TreeNode *minkeyNode(TreeNode *node)
  {
    TreeNode *current = node;
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
    {
      current = current->left;
    }
    return current;
  }

  TreeNode *deleteNode(TreeNode *r, pt v)
  {
    // base case
    if (r == NULL)
    {
      return NULL;
    }
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    else if (v.r < r->key.l)
    {
      r->left = deleteNode(r->left, v);
    }
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (v.l > r->key.r)
    {
      r->right = deleteNode(r->right, v);
    }
    // if key is same as root's key, then This is the node to be deleted
    else
    {
      // node with only one child or no child
      if (r->left == NULL)
      {
        TreeNode *temp = r->right;
        delete r;
        return temp;
      }
      else if (r->right == NULL)
      {
        TreeNode *temp = r->left;
        delete r;
        return temp;
      }
      else
      {
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        TreeNode *temp = minkeyNode(r->right);
        // Copy the inorder successor's content to this node
        r->key = temp->key;
        // Delete the inorder successor
        r->right = deleteNode(r->right, temp->key);
        //deleteNode(r->right, temp->key);
      }
    }

    int bf = getBalanceFactor(r);
    // Left Left Imbalance/Case or Right rotation
    if (bf == 2 && getBalanceFactor(r->left) >= 0)
      return rightRotate(r);
    // Left Right Imbalance/Case or LR rotation
    else if (bf == 2 && getBalanceFactor(r->left) == -1)
    {
      r->left = leftRotate(r->left);
      return rightRotate(r);
    }
    // Right Right Imbalance/Case or Left rotation
    else if (bf == -2 && getBalanceFactor(r->right) <= -0)
      return leftRotate(r);
    // Right Left Imbalance/Case or RL rotation
    else if (bf == -2 && getBalanceFactor(r->right) == 1)
    {
      r->right = rightRotate(r->right);
      return leftRotate(r);
    }

    return r;
  }

  void search(TreeNode *root, pt &key, LL &d, LL x)
  {
    ////cout<<"inside search"<<"\n";

    if (root == NULL)
      return;
    if (root->key.l <= x && root->key.r >= x)
    {
      d = 0;
      key.l = root->key.l;
      key.r = root->key.r;
    }
    else if (root->key.l > x)
    {
      if (root->key.l - x < d || (root->key.l - x == d && key.l > root->key.r))
      {
        d = root->key.l - x;
        key.l = root->key.l;
        key.r = root->key.r;
      }
      search(root->left, key, d, x);
    }
    else
    {
      if (x - root->key.r < d || (x - root->key.r == d && key.l > root->key.r))
      {
        d = x - root->key.r;
        key.l = root->key.l;
        key.r = root->key.r;
      }
      search(root->right, key, d, x);
    }
  }

  TreeNode *iterativeSearch(pt v)
  {
    if (root == NULL)
    {
      return root;
    }
    else
    {
      TreeNode *temp = root;
      while (temp != NULL)
      {
        if (v.l == temp->key.l || v.r == temp->key.r)
        {
          return temp;
        }
        else if (v.r < temp->key.l)
        {
          temp = temp->left;
        }
        else
        {
          temp = temp->right;
        }
      }
      return NULL;
    }
  }
};
void merge(LL arr[], int p, int q, int r)
{

  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  LL L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2)
  {
    if (L[i] >= M[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(LL arr[], int l, int r)
{
  if (l < r)
  {
    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
  }
}

int main()
{
  fastio; 
  int t = 1;
  cin >> t;
  int T = 1;
  while (t--)
  {
    fr = 0;
    AVLTree obj;
    int n, m;
    cin >> n >> m;
    LL *v1, *v2, *vv, *ans;

    // v1 = new LL[n];
    // v2 = new LL[n];

    vv = new LL[m];
    ans = new LL[m];
    // FOR(i, 0, n)
    // {
    //   cin >> v1[i] >> v2[i];
    // }

    FOR(i, 0, n)
    {
      LL x, y;
      cin >> x >> y;
      bool ok = true;
      //cout << "INSERTING!!!!!!!!!!!!!!!! " << x << " " << y << "\n";
      obj.root = obj.insert(obj.root, new TreeNode(pt(x, y)), ok);
    }
    FOR(i, 0, m)
    cin >> vv[i];
    mergeSort(vv, 0, m - 1);
    FOR(i, 0, m)
    {
      fr = 1;
      LL x = vv[i];
      LL d = 1e18;
      pt p = pt(1e18, 1e18);
      obj.search(obj.root, p, d, x);
      obj.root = obj.deleteNode(obj.root, p);
      LL k = x - d >= p.l && x - d <= p.r ? x - d : x + d;
      ans[i] = k;
      //cout << p.l << " ++++++++++++ " << p.r << " ++++++++++++ " << k << " ++++++++++++ " << d << "\n";
      if (p.l == p.r)
        continue;
      bool ok = 1;
      if (p.l == k)
      {
        obj.root = obj.insert(obj.root, new TreeNode(pt(k + 1, p.r)), ok);
      }
      else if (p.r == k)
      {
        obj.root = obj.insert(obj.root, new TreeNode(pt(p.l, k - 1)), ok);
      }
      else
      {
        obj.root = obj.insert(obj.root, new TreeNode(pt(p.l, k - 1)), ok);
        obj.root = obj.insert(obj.root, new TreeNode(pt(k + 1, p.r)), ok);
      }
    }
    printf("Case #%d: ", T++);
    for (int i = 0; i < m; i++)
      printf("%lld ", ans[i]);
    printf("\n");
  }
}

}
