#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

#define mem(dp,a)       memset(dp,a,sizeof dp)
#define ninja           ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb(x)           push_back(x)
#define all(c)          c.begin(), c.end()
#define int             long long
#define ff              first
#define ss              second
#define nl              '\n'

set<int> adj[200005];
bool vis[200005];
vector<int> path;

bool dfs(int s, int p){
	vis[s]=1;
	path.pb(s);
	for(auto i:adj[s]){
		if(!vis[i]){
			if(dfs(i,s))
			return true;
		}
		if(vis[i] and i!=p){
                path.pb(i);
			return true;
		}
	}
	return false;
}
int32_t main()
{
	ninja
	int n,k; cin>>n>>k;
	int x;
	for(int i=1;i<=n;i++){
		cin>>x;
		adj[i].insert(x);
	}
	mem(vis,false);
	bool cycle=dfs(1,-1);
	   for(auto i:path)
    cout<<i<<" ";
     cout<<endl;

	int i=0,j=path.size()-1;
	while(i<j){
		if(path[i]==path[j]){
			break;
		}
		i++;
	}
	int temp =k;
	 k = k- i;
	 if(k<0){
	 	cout<<path[i]<<" ";return 0;
	 }
	// cout<<j<<' '<<i<<nl;
	int final_dest = (k)%(j-i) + i;
	// if(i>0)
 //    path.erase(path.begin(),path.begin()+i-1);

    //cout<<final_dest<<endl;
	cout<< path[final_dest];
}

