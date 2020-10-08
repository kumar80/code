#include <bits/stdc++.h> 
using namespace std; 
#define MAXN 100007 
#define level 18 
#define LL long long 

vector <int> tree[MAXN]; 
int depth[MAXN]; 
int parent[MAXN][level]; 
#define FOR(i, j, k) for (auto i=j ; i<k ; i++)
#define ROF(i, j, k) for (auto i=j ; i>=k ; i--) 

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

int lca(int u, int v) 
{ 
	if (depth[v] < depth[u]) 
		swap(u, v); 

	int diff = depth[v] - depth[u]; 

	for (int i=0; i<level; i++) 
		if ((diff>>i)&1) 
			v = parent[v][i]; 

	if (u == v) 
		return u; 

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
vector<int>ods(MAXN,0);
vector<int>ev(MAXN,0);
vector<int>val(MAXN);
LL p1=0,p2=0;
void dfs2(int u, int p){
    ods[u]=ods[p]; ev[u]=ev[p];
    if(u&1) p1+=val[u],ods[u]++;
    else p2+=val[u],ev[u]++;
       // cout<<u<<" "<<ods[u]<<" ";

    for(auto v : tree[u]){
        if(v!=p) dfs2(v,u);
        
    }
}
int main() 
{   int n; cin>>n; 
    FOR(i,1,n+1) cin>>val[i];
	memset(parent,-1,sizeof(parent)); 
    FOR(i,0,n-1) {
        int x,y; cin>>x>>y; 
        addEdge(x,y);
    }
	depth[0] = 0; 
	dfs(1,0); 
    dfs2(1,0);
	precomputeSparseMatrix(n); 
    int q; cin>>q;
    FOR(i,0,q ) {
        int a,b,x; cin>>a>>b>>x;
        int lc = lca(a,b),o=0,e=0;
        o = ods[a] + ods[b] - 2*ods[lc]+ (lc&1);
        e = ev[a] + ev[b] - 2*ev[lc] + (lc%2==0) ;
       // cout<<"\n";
       // cout<<ods[a] <<" "<<ods[b]<<" "<<ods[lc]<<"; ";
        //cout<<ev[a] <<" "<<ev[b]<<" "<<ev[lc]<<"; ";
      //  cout<<lc<<" "<<o<<" "<<e<<"\n";
        p1+=x*o; p2+=x*e;  
    }
    cout<<abs(p1-p2);
} 
