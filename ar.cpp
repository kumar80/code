// A C++ program to find bridges in a given undirected graph 
#include<bits/stdc++.h>
using namespace std;
#define NIL -1 
#define FOR(i, j, k) for (auto i=j ; i<k ; i++)

using namespace std; 

int V; 
vector<int> adj[1000*1000];
     vector<pair<int,int>>ans;

void addEdge(int v, int w) 
{ 
	adj[v].push_back(w); 
	adj[w].push_back(v); 
} 

void bridgeUtil(int u, bool visited[], int disc[], 
								int low[], int parent[]) 
{ 
	static int time = 0; 

	visited[u] = true; 

	disc[u] = low[u] = ++time; 

	vector<int>::iterator i; 
	for (i = adj[u].begin(); i != adj[u].end(); ++i) 
	{ 
		int v = *i;

		if (!visited[v]) 
		{ 
			parent[v] = u; 
			bridgeUtil(v, visited, disc, low, parent); 


			low[u] = min(low[u], low[v]); 

			if (low[v] > disc[u]) 
                ans.push_back({u,v});
		} 

		else if (v != parent[u]) 
			low[u] = min(low[u], disc[v]); 
	} 
} 


void bridge() 
{ 
	bool *visited = new bool[V]; 
	int *disc = new int[V]; 
	int *low = new int[V]; 
	int *parent = new int[V]; 

	for (int i = 0; i < V; i++) 
	{ 
		parent[i] = NIL; 
		visited[i] = false; 
	} 


	for (int i = 0; i < V; i++) 
		if (visited[i] == false) 
			bridgeUtil(i, visited, disc, low, parent); 
} 

vector<pair<int,int>> f( int n , int r,  vector<pair<int,int>>ro)
{   V=n;
    FOR(i,0,r) addEdge(ro[i].first,ro[i].second);

	bridge(); 


    return ans;
	
} 
int main(){
    vector<pair<int,int>> x;x.push_back({1,2}); x.push_back({2,3});
    vector<pair<int,int>> p= f(3,2,x);
    for(auto i : p) cout<<i.first<<" ";
}
