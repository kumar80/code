#include<iostream>
#include<vector>

using namespace std;

vector<int> f(vector<int>v){
    int d = 1;
    while(1){
        bool ok = false;
        if(v[0] - d <= 0){
            v[0]  = d ;
            ok = true;
        }
        v.push_back(v[0]-d);
        v.erase(v.begin());
        d++;
        if(d>5) d=1;
        if(ok) break;
    }
    return v;
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
	//cin>>T;

	/*
	   Read each test case from standard input.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int t; cin>>t;
        vector<int>v(8);
        for(int i=0;i<8;i++){
            cin>>v[i];
        }
        v=f(v);
        cout<<"#"<<test_case<<" ";
        for(auto i : v) cout<<i<<" ";
        cout<<"\n";
	}
	return 0;//Your program should return 0 on normal termination.
}