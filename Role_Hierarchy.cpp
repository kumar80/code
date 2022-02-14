/*
Features:
1. Create the root role and display it.
2. add sub role operation to the root role.
3. display the roles in role hierarchy order.
4. Support delete role operation, transfer children to the role entered by the user as input.
(If the role to be transferred is the child role of the deleted role, then also the
parent of deleted role becomes the parent of the role to be transferred.)
5. Users can be added and a role can be assigned to them. Same role can be assigned to
more than one user but an user can have only single role.
6. Display users.
7. Display each user with the list of users who are working under the particular user.
9. Support delete user operation.
9. find the number of users between the top most role user and the entered user.
10. find the height of the entire role hierarchy.
11. find the top most common boss of the entered users.

-----------------
Assumptions:
    1. All inputs are valid
    2. No two user have the same name

*/

#include <bits/stdc++.h>
using namespace std;

class User
{
    string userName;

public:
    User(string _userName = "")
    {
        userName = _userName;
    }
    string getUserName()
    {
        return userName;
    }
};

class roleTree
{
    roleTree *parent;
    vector<roleTree *> children;
    vector<User> users;
    string roleName;
    int level;
    static unordered_map<string, roleTree *> roleTreeNode; // roleName to roleTreeNode
    static unordered_map<string, string> role;             // userName to roleName

    void setRoleName(string _roleName)
    {
        roleName = _roleName;
    }

    string getRoleName()
    {
        return roleName;
    }

    void addToUsers(User user)
    {
        users.push_back(user);
    }

    void removeFromUsers(string userName)
    {
        for (int i = 0; i < users.size(); i++)
        {
            if (users[i].getUserName() == userName)
            {
                users.erase(users.begin() + i);
                break;
            }
        }
        auto it = role.find(userName);
        role.erase(it);
    }

    vector<User> getUsers()
    {
        return users;
    }

    void mapRoleNameToNode(roleTree *role)
    {
        roleTreeNode.insert({roleName, role});
    }

    void mapUserNameToRoleName(string userName)
    {
        role.insert({userName, roleName});
    }

    roleTree *getRoleNode(string _roleName)
    {
        auto it = roleTreeNode.find(_roleName);
        return it->second;
    }

    roleTree *getParentRole()
    {
        return parent;
    }

    vector<roleTree *> getChildren()
    {
        return children;
    }

    void addChildRole(roleTree *_child)
    {
        children.push_back(_child);
    }

    void removeChildRole(roleTree *_child)
    {
        auto it = find(children.begin(), children.end(), _child);
        children.erase(it);
    }

    int getLevel()
    {
        return level;
    }

public:
    roleTree(string _roleName = "", roleTree *_parent = NULL)
    {
        children = vector<roleTree *>();
        users = vector<User>();
        roleName = _roleName;
        parent = _parent;
        if (parent != NULL)
        {
            level = parent->level + 1;
        }
        else
        {
            level = 0;
        }
    }
    void setRootRole(roleTree *root);
    void addSubRole(roleTree *root);
    void displayRoleTree(roleTree *root);
    void deleteRole(roleTree *root);
    void addUser(roleTree *root);
    void displayUsers(roleTree *root);
    void displayUsersAndSubUsers(roleTree *root);
    void deleteUser(roleTree *root);
    int getNoOfUsersFromTop(roleTree *root);
    int getHeight(roleTree *root);
    int dfs(roleTree *root, vector<pair<User, pair<int, int>>> &users);
    vector<User> getCommonBoss(roleTree *root);
};

unordered_map<string, roleTree *> roleTree::roleTreeNode = unordered_map<string, roleTree *>();
unordered_map<string, string> roleTree::role = unordered_map<string, string>();

int takeUserInput()
{
    int input;
    cin >> input;
    return input;
}

void roleTree::setRootRole(roleTree *root)
{
    string roleName;
    cin >> roleName;
    setRoleName(roleName);
    mapRoleNameToNode(root);
}

void roleTree::addSubRole(roleTree *root)
{
    string roleName, reportingRoleName;
    cin >> roleName >> reportingRoleName;
    roleTree *role = root->getRoleNode(reportingRoleName);
    roleTree *newRole = new roleTree(roleName, role);
    newRole->mapRoleNameToNode(newRole);
    role->addChildRole(newRole);
}

void roleTree::displayRoleTree(roleTree *root)
{
    queue<roleTree *> q;
    q.push(root);
    while (!q.empty())
    {
        int len = q.size();
        while (len--)
        {
            roleTree *role = q.front();
            q.pop();
            cout << role->getRoleName() << ", ";
            for (auto r : role->getChildren())
                q.push(r);
        }
    }
}

void roleTree::deleteRole(roleTree *root)
{
    string roleName, transferRoleName;
    cin >> roleName >> transferRoleName;

    roleTree *delRole = getRoleNode(roleName);
    roleTree *transferRole = getRoleNode(transferRoleName);
    roleTreeNode.erase(roleTreeNode.find(roleName));

    vector<roleTree *> children = delRole->getChildren();
    bool trasferNodeIsChild = false;
    for (auto role : children)
    {
        if (role == transferRole)
        {
            trasferNodeIsChild = true;
        }
    }
    roleTree *parent = delRole->getParentRole();
    if (parent == NULL)
        return;
    parent->removeChildRole(delRole);

    if (trasferNodeIsChild)
    {
        parent->addChildRole(transferRole);
    }

    for (auto role : children)
        if (role != transferRole)
            transferRole->addChildRole(role);
}

void roleTree::addUser(roleTree *root)
{
    string userName, roleName;
    cin >> userName >> roleName;
    roleTree *role = getRoleNode(roleName);
    role->addToUsers(User(userName));
    role->mapUserNameToRoleName(userName);
}

void roleTree::displayUsers(roleTree *root)
{
    queue<roleTree *> q;
    q.push(root);
    while (!q.empty())
    {
        roleTree *role = q.front();
        q.pop();
        cout << role->getRoleName() << " - ";
        for (auto user : role->getUsers())
        {
            cout << user.getUserName() << " ";
        }
        cout << "\n";
        for (auto r : role->getChildren())
            q.push(r);
    }
}

int roleTree::dfs(roleTree *root, vector<pair<User, pair<int, int>>> &users)
{
    int len = 0;
    for (auto child : root->getChildren())
    {
        len += dfs(child, users);
    }
    int l = 0;
    for (auto user : root->getUsers())
        users.push_back({user, {++l, len}});
    return len + root->users.size();
}

void roleTree::displayUsersAndSubUsers(roleTree *root)
{
    vector<pair<User, pair<int, int>>> users;
    dfs(root, users);
    for (int i = users.size() - 1; i >= 0; i--)
    {
        int s = i - users[i].second.first, e = s - users[i].second.second;
        cout << users[i].first.getUserName() << " - ";
        for (int j = s; j > e; j--)
        {
            cout << users[j].first.getUserName() << ", ";
        }
        cout << "\n";
    }
}

void roleTree::deleteUser(roleTree *root)
{
    string userName;
    cin >> userName;
    string roleName = role.find(userName)->second;
    roleTree *role = roleTreeNode.find(roleName)->second;
    role->removeFromUsers(userName);
}

int roleTree::getNoOfUsersFromTop(roleTree *root)
{
    string userName;
    cin >> userName;
    string roleName = role.find(userName)->second;
    roleTree *role = roleTreeNode.find(roleName)->second->getParentRole();
    int cnt = 0;
    while (role != NULL)
    {
        cnt += role->users.size();
        role = role->parent;
    }
    return cnt;
}

int roleTree::getHeight(roleTree *root)
{
    queue<roleTree *> q;
    q.push(root);
    int height = 0;
    while (!q.empty())
    {
        roleTree *role = q.front();
        q.pop();
        height = max(role->getLevel() + 1, height);
        for (auto r : role->getChildren())
            q.push(r);
    }

    return height;
}

vector<User> roleTree::getCommonBoss(roleTree *root)
{
    string user1, user2;
    cin >> user1 >> user2;
    string roleName1 = root->role.find(user1)->second;
    roleTree *role1 = root->roleTreeNode.find(roleName1)->second;
    string roleName2 = root->role.find(user2)->second;
    roleTree *role2 = root->roleTreeNode.find(roleName2)->second;
    stack<roleTree *> roles1, roles2;
    while (role1 != NULL)
    {
        roles1.push(role1);
        role1 = role1->getParentRole();
    }
    while (role2 != NULL)
    {
        roles2.push(role2);
        role2 = role2->getParentRole();
    }
    roleTree *par = NULL;
    while (!roles1.empty() && !roles2.empty())
    {
        if (roles1.top() != roles2.top())
        {
            break;
        }
        par = roles1.top();
        roles1.pop();
        roles2.pop();
    }
    return par->getUsers();
}

int main()
{
    roleTree *root = new roleTree();

    cout << "Press 1 to enter root role name\n";
    cout << "Press 2 to add sub role  the root role \n";
    cout << "Press 3 to display the roles in role hierarchy in order \n";
    cout << "Press 4 to delete role \n";
    cout << "Press 5 to add User \n";
    cout << "Press 6 to display Users \n";
    cout << "Press 7 to display Users and sub users \n";
    cout << "Press 8 to delete user \n";
    cout << "Press 9 to find no of users from top \n";
    cout << "Press 10  to find height of role hierarchy \n";
    cout << "Press 11 to display common boss of user \n";
    cout << "Press 0 to exit\n";

    while (1)
    {
        bool done = false;
        switch (takeUserInput())
        {
        case 1:
            cout << "Please enter root role name \n";
            root->setRootRole(root);
            break;
        case 2:
            cout << "Please enter sub role and reporting role name \n";
            root->addSubRole(root);
            break;
        case 3:
            root->displayRoleTree(root);
            break;
        case 4:
            cout << "Please enter role to be deleted and role name to be transferred\n";
            root->deleteRole(root);
            break;
        case 5:
            cout << "Please enter user name  and role \n";
            root->addUser(root);
            break;
        case 6:
            root->displayUsers(root);
            break;
        case 7:
            root->displayUsersAndSubUsers(root);
            break;
        case 8:
            cout << "Please enter username to be deleted\n";
            root->deleteUser(root);
            break;
        case 9:
            cout << "Please enter username\n";
            cout << root->getNoOfUsersFromTop(root);
            break;
        case 10:
            cout << root->getHeight(root);
            break;
        case 11:
            cout << "Please enter username 1 and username 2\n";
            for (auto boss : root->getCommonBoss(root))
            {
                cout << boss.getUserName() << ", ";
            }
            break;
        case 0:
            done = true;
            break;
        default:
            break;
        }

        if (done)
            break;
    }
}
