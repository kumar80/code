
#include <bits/stdc++.h>
using namespace std;


pair<int,int> printClosest(vector<vector<int>> ar1, vector<vector<int>> ar2, int m, int n, int x)
{
	int diff = INT_MAX;
	int res_l=-1, res_r=-1;

	int l = 0, r = n-1;
	while (l<m && r>=0)
	{
	if (abs(ar1[l][1] + ar2[r][1] - x) < diff)
	{
		res_l = l;
		res_r = r;
		diff = abs(ar1[l][1] + ar2[r][1] - x);
	}
	if (ar1[l][1] + ar2[r][1] > x)
		r--;
	else 
		l++;
	}
    if(res_l==-1) return {-1,-1};

    return {ar1[res_l][1],ar2[res_r][1]};
}

bool cmp(vector<int>&a, vector<int>&b){
    return (a[1]==a[1] ? a[0]<b[0]: a[1]<b[1]);
}

int main()
{
	vector<vector<int>> ar1 = {{2,7},{3,14}};// {{1,3},{2,5},{3,7},{4,10}};
	vector<vector<int>> ar2  = {{2,10},{3,14}}; //{{1,2},{2,3},{3,4},{4,5}};
    vector<int>a1[10000];
    vector<int>a2[10000];
    sort(ar1.begin(),ar1.end(),cmp);
    sort(ar2.begin(),ar2.end(),cmp);
    map<int,int>m1,m2;
	int x = 16;
	int n = ar1.size();
	int m = ar2.size();
    for(int i=0;i<n;i++) a1[ar1[i][1]].push_back(ar1[i][0]),m1[ar1[i][1]]++;
    for(int i=0;i<m;i++) a2[ar2[i][1]].push_back(ar2[i][0]),m2[ar2[i][1]]++;
	auto pr = printClosest(ar1, ar2, n, m, x);

    vector<pair<int,int>>res;
    int p = pr.first,q=pr.second;
    int tot = p+q; 
    for(int i=0;i<n && tot<=x;i++){
        int s = ar1[i][1],e = tot-s;
        if(!m2[e] ) continue;
            for(int j=0;j<a1[s].size();j++){
                for(int k=0;k<a2[e].size();k++) res.push_back({a1[s][j],a2[e][k]});
            }
        }
    for(auto i : res) cout<<i.first<<" "<<i.second<<"\n";
	return 0;
}

