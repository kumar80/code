#include<bits/stdc++.h>
#include<vector>

using namespace std;
int find(int x, vector<int>&p){
    if(x==p[x]) return x;

    return p[x] = find(p[x],p);
}
int uni(vector<int>&p, vector<int>&s, int x, int y){
    x = find(x,p);
    y = find(y,p);
    if(x!=y){
        if(s[x]<s[y]) swap(x,y);
        p[y]  = x;
        s[x]+=s[y];
        return 1;
    }
    return 0;
}
int main(int argc, char** argv)
{
	int test_case;
	int T=10;
	/* 
	The freopen function below opens input.txt in read only mode and 
	sets your standard input to work with the opened file. 
	When you test your code with the sample data, you can use the function
	below to read in from the sample data file instead of the standard input.
	So. you can uncomment the following line for your local test. But you
	have to comment the following line when you submit for your scores.
	*/

	//freopen("input.txt", "r", stdin);
	cin>>T;

	/*
	   Read each test case from standard input.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{   int n; cin>>n;
        long long co[n][2]; double e;
        for(int i=0;i<n;i++) cin>>co[i][0];
        for(int i=0;i<n;i++) cin>>co[i][1];
        cin>>e;
        vector<pair<  double  ,pair<int,int>>> v;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                 double  l = (co[i][0] - co[j][0])*(co[i][0] - co[j][0]) + (co[i][1]-co[j][1])*(co[i][1]-co[j][1]);
                l*=e;
                v.push_back({l,{i,j}});
            }
        }
        sort(v.begin(),v.end());
        int l = v.size();
        vector<int>p(n),s(n);
        for(int i=0;i<n;i++) {
            p[i] =i,s[i] = 1;
        }
        double  ans = 0;
        for(int i=0;i<l;i++ ){
            if(uni(p,s,v[i].second.first,v[i].second.second)){
                ans+=v[i].first;
            } 
        }
        cout<<"#"<<test_case<<" ";
        cout<< (long long)round(ans)<<"\n";
       // cout<<fixed<<setprecision(10)<<round(ans)<<"\n";
       
	}
	return 0;//Your program should return 0 on normal termination.
}