#include<bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define LL long long 
#define mod 998244353 
#define FOR(i, j, k) for (int i=j ; i<k ; i++)
#define ROF(i, j, k) for (int i=j ; i>=k ; i--) 
 
const long long INF = 1e18;
const long long MAX = 1e5+10;


int spf[2*MAX]; 
vector<int>v[2*MAX];
vector<int>c(500,0);
void sieve() 
{ 
	spf[1] = 1; 
	for (int i=2; i<2*MAX; i++) 	spf[i] = i; 

	for (int i=4; i<2*MAX; i+=2) 
		spf[i] = 2; 

	for (int i=3; i*i<2*MAX; i++) 
	{ 
		if (spf[i] == i) 
		{ 
			for (int j=i*i; j<2*MAX; j+=i) 
				if (spf[j]==j) 
					spf[j] = i; 
		} 
	} 
} 

void getFactorization(int x) 
{ 
	while (x != 1) 
	{   int cnt =0,y=x; 
        while(x%spf[y]==0 && x>1) x/=spf[y],cnt++;
        // if(v[spf[y]].size()<2){
        //     v[spf[y]].push_back(cnt);
        // }else {
        //     sort(v[spf[y]].begin(),v[spf[y]].end());
        //     if(cnt<v[spf[y]][0]) v[spf[y]][0]=cnt;
        //     else if(cnt>v[spf[y]][0] && v[spf[y]][1]>cnt) v[spf[y]][1]=cnt;
        // }
        // c[spf[y]]++;
        v[spf[y]].push_back(cnt);
    }  

} 

int main(){ 
    fastio;
	sieve(); 
    int n,x; cin>>n; 
	FOR(i,0,n)
        cin>>x, getFactorization(x); 

    LL res = 1;
    FOR(i,2,2*1e5){
        if(v[i].size()<n-1) continue;
        sort(v[i].begin(),v[i].end());
        if(v[i].size()==n-1) res*=pow(i,v[i][0]);
        else res*=pow(i,v[i][1]);
    }
    cout<<res;
	return 0; 
} 
