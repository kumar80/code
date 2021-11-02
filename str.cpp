#include<bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

int main(){
    fastio;
    int test_case;
	int T=1;
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
            string s,a; cin>>a>>s;
            int cnt =0;
            for(int i=0;i<s.size()-a.size()+1;i++){
                bool ok = true;
                int k = i;
                for(int j=0;j<a.size();j++){
                    if(a[j] !=s[k]) ok=false;
                    k++;
                }
                if(ok) cnt++;
            }
        cout<<"#"<<t<<" "<<cnt<<"\n";
	}
}