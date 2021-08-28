#include <bits/stdc++.h>
using namespace std;
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)

struct Node
{
    string name;
    bool islock;
    int LockId;
    bool descLock;
    int childLockId;
    vector<Node *> child;
    Node(string v)
    {
        name = v;
        islock = false;
        descLock = false;
        childLockId = 0;
        LockId = 0;
    }
};
bool ans;
void addChild(Node *p, Node *child)
{
    p->child.push_back(child);
}

bool lock(Node *node, string name, int uid, Node *p)
{
    if (node == nullptr)
        return false;
    if (node->islock || node->descLock)
        return true;
    if (node->name == name)
    {
        node->LockId = uid;
        ans = true;
        return node->islock = true;
    }
    bool res = false, sameId = 0;

    for (int i = 0; i < node->child.size(); i++)
    {
        res = res || lock(node->child[i], name, uid, node);
        if (node->child[i]->LockId == -1)
        {
            sameId = -1;
        }
        if (sameId == 0)
            sameId = node->child[i]->LockId;
        if (sameId > 0)
        {
            if (node->child[i]->LockId != sameId)
                sameId = 0;
        }
    }
    node->LockId = sameId;

    return node->descLock = res;
}

bool unLock(Node *node, string name, int uid, Node *p)
{
    if (node == nullptr)
        return false;
    if (node->name == name)
    {
        if (!node->islock)
        {
            ans = false;
            return node->islock;
        }
        node->LockId = 0;
        ans = true;
        return node->islock = false;
    }
    bool res = false, sameId = 0;
    for (int i = 0; i < node->child.size(); i++)
    {
        res = res || lock(node->child[i], name, uid, node);
        if (node->child[i]->LockId == -1)
        {
            sameId = -1;
        }
        if (sameId == 0)
            sameId = node->child[i]->LockId;
        if (sameId > 0)
        {
            if (node->child[i]->LockId != sameId)
                sameId = 0;
        }
    }
    node->LockId = sameId;
    return node->descLock = res;
}

bool upgrade(Node *node, string name, int uid)
{
    if (node == nullptr)
        return false;
    if (node->name == name)
    {
        if (!node->islock)
        {
            ans = false;
            return node->islock;
        }
        ans = true;
        return node->islock = false;
    }
    bool res = false, sameId = 0;
    for (int i = 0; i < node->child.size(); i++)
    {
        res = res || lock(node->child[i], name, uid, node);
        if (sameId == 0)
            sameId = node->child[i]->LockId;
        if (sameId > 0)
        {
            if (node->child[i]->LockId != sameId)
                sameId = 0;
        }
    }
    node->childLockId = sameId;
    return node->descLock = res;
}
int main()
{
    fastio;
    int n, m, query;
    cin >> n >> m >> query;
    queue<Node *> q;
    string s;
    cin >> s;
    Node *root = new Node(s);
    q.push(root);
    int i = 1;
    while (i < n)
    {
        int l = q.size();
        for (int j = 0; j < l; j++)
        {
            Node *tr = q.front();
            q.pop();
            for (int k = 0; k < m; k++)
            {
                cin >> s;
                tr->child.push_back(new Node(s));
                i++;
            }
        }
    }
    for (i = 0; i < query; i++)
    {
        int a, b;
        cin >> a >> s >> b;
    }
}