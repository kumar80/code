#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T=10;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{	
		int t; cin>>t;
		int n; cin>>n;
		vector<int>v(10,0);
		vector<string>mp = {"ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN"};
		map<string,int>m;
		for(int i=0;i<10;i++) m[mp[i]] = i;
		for(int i=0;i<n;i++) {
			string s; cin>>s;
			v[m[s]]++;
		}
		cout<<"#"<<test_case<<"\n";
		for(int i = 0;i<10;i++){
			for(int j=0;j<v[i];j++){
				cout<<mp[i]<<" ";
			}
		}
	}
	return 0;//Your program should return 0 on normal termination.
}