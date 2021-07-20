#include <iostream>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
#define LL long long
#define FOR(i, j, k) for (auto i = j; i < k; i++)

struct pt
{
    LL l, r;
    pt(LL x, LL y)
    {
        l = x;
        r = y;
    }
    pt() {}
};

struct Node
{
    pt key;
    Node *left;
    Node *right;
    int height;
};

int max(int a, int b);

int height(Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

Node *newNode(pt key)
{
    Node *node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return (node);
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left),
                    height(y->right)) +
                1;
    x->height = max(height(x->left),
                    height(x->right)) +
                1;

    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left),
                    height(x->right)) +
                1;
    y->height = max(height(y->left),
                    height(y->right)) +
                1;

    return y;
}

int getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) -
           height(N->right);
}

Node *insert(Node *node, pt key)
{
    if (node == NULL)
        return (newNode(key));

    if (key.r < node->key.l)
        node->left = insert(node->left, key);
    else if (key.l > node->key.r)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left),
                           height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key.r < node->left->key.l)
        return rightRotate(node);
    if (balance < -1 && key.l > node->right->key.r)
        return leftRotate(node);
    if (balance > 1 && key.l > node->left->key.r)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key.r < node->right->key.l)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node *minValueNode(Node *node)
{
    Node *current = node;
    while (current->left != NULL)
        current = current->left;

    return current;
}

Node *deleteNode(Node *root, pt key)
{
    if (root == NULL)
        return root;

    if (key.r < root->key.l)
        root->left = deleteNode(root->left, key);
    else if (key.l > root->key.r)
        root->right = deleteNode(root->right, key);
    else
    {
        if ((root->left == NULL) ||
            (root->right == NULL))
        {
            Node *temp = root->left ? root->left : root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else
        {
            Node *temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right,
                                     temp->key);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left),
                           height(root->right));

    int balance = getBalance(root);

    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 &&
        getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 &&
        getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void search(Node *root, pt &key, LL &d, LL x)
{
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
void merge(pt arr[], int p, int q, int r)
{

    int n1 = q - p + 1;
    int n2 = r - q;

    pt L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2)
    {
        if (L[i].l >= M[j].l)
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

void mergeSort(pt arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
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
        Node *root = NULL;
        int n, m;
        cin >> n >> m;
        pt v[n];
        pt vv[m];
        LL ans[m];
        FOR(i, 0, n)
        {
            cin >> v[i].l >> v[i].r;
        }
        FOR(i, 0, m)
            cin >> vv[i].l;
        FOR(i, 0, m)
            cin >> vv[i].r;
        FOR(i, 0, n)
        {
            root = insert(root, pt(v[i].l, v[i].r));
        }
        mergeSort(vv, 0, m - 1);

        FOR(i, 0, m)
        {
            LL x = vv[i].r;
            LL d = 1e18;
            pt p = pt((LL)100000*100000*100000, (LL)100000*100000*100000);
            search(root, p, d, x);
            root = deleteNode(root, pt(p.l, p.r));
            LL k = x - d >= p.l && x - d <= p.r ? x - d : x + d;

            ans[i] = k;
            if (p.l == p.r)
                continue;
            if (p.l == k)
                root = insert(root, pt(k + 1, p.r));
            else if (p.r == k)
                root = insert(root, pt(p.l, k - 1));
            else
            {
                root = insert(root, pt(p.l, k - 1));
                root = insert(root, pt(k + 1, p.r));
            }
        }
        printf("Case #%d: ", T++);
        for (int i = 0; i < m; i++)
            printf("%lld ", ans[i]);
        printf("\n");
    }
}
