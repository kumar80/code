#include<bits/stdc++.h>
using namespace std;
class RemoveNodes {
public:
	// DO NOT read from stdin or write to stdout
	// Input is given as function argument
	// Output is taken as the function return value
    vector<int>adj[1000*1000];      
    vector<bool>vis,pos;

    bool dfs(int u, int A){
        if(vis[u])  return pos[u];
        vis[u] = 1;
        pos[u] = (u==A) ;
        for(auto v : adj[u]) {
            pos[u] = pos[u] || dfs(v,A);
        }
    
        return pos[u];
    }
	std::vector<int> findMinimalRemoval(int N, int M, int A, int B, std::vector<int> edgeFrom, std::vector<int> edgeTo) {
		// Code here
        for(int i = 0;i<edgeFrom.size();i++){
            adj[edgeTo[i]].push_back(edgeFrom[i]);
        }
        vector<int>ans;
        vis.resize(1000*1000,false);
        pos.resize(1000*1000,false);
        for(auto i : adj[B]){
            dfs(i,A);
            if(pos[i]) ans.push_back(i);
            cout<<i<<" "<<pos[i]<<" ;";
        }
        sort(ans.begin(),ans.end());
        return ans;
	}
};
