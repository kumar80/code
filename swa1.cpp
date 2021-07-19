
#include<bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define LL long long 
#define mod 1000000007 
#define FOR(i, j, k) for (int i=j ; i<k ; i++)
#define ROF(i, j, k) for (int i=j ; i>=k ; i--) 
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false); debug("%s time : %.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))

const long long INF = 1e18;
const long long MAX = 1e5+10;

int main(){
    fastio;
    int t=11;// cin>>t; 
    vector<string>ans;
    queue<string>q; q.push("+");
    ans.push_back("***");

    while(ans.size()<4000){
        string s = q.front();
        q.pop(); ans.push_back(s);
        q.push(s+'-');
        q.push(s+'0');
        q.push(s+'+');
    }    
    vector<string>v(4000);
    v.push_back("***");
    v[0]="0"; v[1] = "+"; v[2] = "+-"; v[3] = "+0";
    FOR(i,4,4000){
        if(i%3 ==0){
            v[i] = v[i/3] + '0';
        }else if(i%3 == 1){
            v[i] = v[i-1];
            v[i][v[i].size()-1] = '+';
        }else {
             v[i] = v[ceil((float)i/3)] + '-';
        }
    }

    while(t--){
        int n=3000; ///cin>>n;
        int p =  rand()%n;
        cout<<p<<": ";
        cout<<(v[p] == ans[p])<<endl;
    }
}