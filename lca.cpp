// Sparse Matrix DP approach to find LCA of two nodes
#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000
#define level 18

vector <int> tree[MAXN];
int depth[MAXN];
int parent[MAXN][level];

// pre-compute the depth for each node and their
// first parent(2^0th parent)
// time complexity : O(n)
void dfs(int cur, int prev)
{
	depth[cur] = depth[prev] + 1;
	parent[cur][0] = prev;
	for (int i=0; i<tree[cur].size(); i++)
	{
		if (tree[cur][i] != prev)
			dfs(tree[cur][i], cur);
	}
}

// Dynamic Programming Sparse Matrix Approach
// populating 2^i parent for each node
// Time complexity : O(nlogn)
void precomputeSparseMatrix(int n)
{
	for (int i=1; i<level; i++)
	{
		for (int node = 1; node <= n; node++)
		{
			if (parent[node][i-1] != -1)
				parent[node][i] =
					parent[parent[node][i-1]][i-1];
		}
	}
}

// Returning the LCA of u and v
// Time complexity : O(log n)
int lca(int u, int v)
{
	if (depth[v] < depth[u])
		swap(u, v);

	int diff = depth[v] - depth[u];

	// Step 1 of the pseudocode
	for (int i=0; i<level; i++)
		if ((diff>>i)&1)
			v = parent[v][i];

	// now depth[u] == depth[v]
	if (u == v)
		return u;

	// Step 2 of the pseudocode
	for (int i=level-1; i>=0; i--)
		if (parent[u][i] != parent[v][i])
		{
			u = parent[u][i];
			v = parent[v][i];
		}

	return parent[u][0];
}

void addEdge(int u,int v)
{
	tree[u].push_back(v);
	tree[v].push_back(u);
}
int dist(int x, int y){
    int l = lca(x,y);
    int dis = depth[x]-depth[l] + depth[y]-depth[l];
    return dis;
}
pair<int,int> f(int x, int y, int z){
    int l = lca(y,z);
    int _l = lca(l,x);    
    int dis = dist(_l,x) + dist(_l,y) + dist(_l,z);
    int dis2 = dist(l,x) + dist(l,y) + dist(l,z);
    pair<int,int>p(dis,_l);
    pair<int,int>p2(dis2,l);
    return dis<dis2? p:p2;
}

vector<int>dail(int x, vector<vector<int>>road,vector<vector<int>>days){
    memset(parent,-1,sizeof(parent));
    int n = -1;
    for(int i=0;i<road.size();i++) {	
        addEdge(road[i][0],road[i][1]);
        n = max(n,road[i][0]);
        n = max(n,road[i][1]);
    }
    depth[0] = 0;
    dfs(1,0);
    precomputeSparseMatrix(n);
    vector<int>ans;
    for(int i=0;i<days.size();i++) {
        int y = days[i][0],z=days[i][1];
        int dis = INT_MAX,res;
        pair<int,int> d1 = f(x,y,z); 
        pair<int,int> d2 = f(z,x,y); 
        pair<int,int> d3 = f(y,z,x); 
        if(d1.first<dis) {dis=d1.first; res=d1.second;}
        if(d2.first<dis) {dis=d2.first; res=d2.second;}
        if(d3.first<dis) {dis=d3.first; res=d3.second;}
        ans.push_back(res);
    }
    return ans;
}
// driver function
int main()
{   
    vector<vector<int>> v = {{3,2},{3,1},{2,4},{2,5}};
    vector<vector<int>> v2 = {{4,5},{1,5}};

	vector<int> res= dail(3,v,v2);
    for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
	return 0;
}
