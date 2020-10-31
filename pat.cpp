#include <iostream> 
using namespace std; 

int countWays(int mtrx[][1001], int vrtx, 
			int i, int dest, bool visited[],int cost , int t) 
{ 
    if(cost>t) return 0;
	if (i == dest && cost==t) { 
		    return 1; 
	} 
	int total = 0; 
	for (int j = 0; j < vrtx; j++) { 
        int temp=cost;
		if (mtrx[i][j] == 1) { 
            temp+=1;
			total += countWays(mtrx, vrtx, 
							j, dest, visited,temp,t); 
			visited[j] = false; 
		} 
	} 

	return total; 
} 
int totalWays(int mtrx[][1001], int vrtx, 
			int src, int dest,int cost,int t) 
{ 
	bool visited[vrtx]; 

	for (int i = 0; i < vrtx; i++) { 
		visited[i] = false; 
	} 
    //cout<<src<<" "<<vrtx;
	visited[src] = true; 

	return countWays(mtrx, vrtx, src, dest, 
					visited,cost,t); 
} 

int main() 
{ 
    int n,x,y,t,m; cin>>n>>x>>y>>t>>m;

    int mtrx[1001][1001];
	int vrtx = n; 
	int src = x; 
	int dest = y; 
    for(int i=0;i<m;i++) {
        int p,q; cin>>p>>q;
        mtrx[p][q]=1; mtrx[q][p]=1;
    }
	cout << totalWays(mtrx, vrtx, src, 
					dest,0,t); 

	return 0; 
} 
