#include<bits/stdc++.h>
using namespace std;

#define FOR(i, j, k) for (auto i=j ; i<k ; i++)

vector<char> findSmallest(string s, vector<vector<int>>qq, int m,vector<int>len) 
{ 
    int N = s.length(); 
    vector<char>ans(m);
    int H[N + 1][26]; 
    memset(H, 0, sizeof(H)); 
    for (int i = 1; i <= N; i++) { 
        ++H[i][s[i - 1] - 'a']; 
        for (int j = 0; j < 26; j++) { 
            H[i][j] += H[i - 1][j]; 
        } 
    } 

    for (int j = 0; j < m; j++) { 
  
        int l = len[qq[j][0]-1]+1, r = len[qq[j][1]], 
            n = qq[j][2]; 
  
        int sum = 0; 

        for (int i = 0; i < 26; i++) { 
            sum += H[r][i] - H[l - 1][i]; 
            if (sum >= n) { 
                ans[j] =   (char)('a' + i); 
                break; 
            } 
        } 
    }

    return ans; 
} 

vector<char> f(int n,vector<string>v,int q,vector<vector<int>>qq){
    string s;
    vector<int>len(n+1);
    len[0]=0;
    FOR(i,0,n){
        s+=v[i]; len[i+1]=v[i].size()+len[i];
    }
    return  findSmallest(s,qq,q,len);   
}

int main(){
    int a[5] = {6,5,3};
    int *p = a;
    FOR(i,0,4) cout<<p[i];
    int n; cin>>n;
    vector<string>v;
    FOR(i,0,n) {
        string s; cin>>s;
        v.push_back(s);
    }
    int q; cin>>q;
    vector<vector<int>>qq;
    FOR(i,0,q){
        vector<int>r(3);
        FOR(j,0,3) cin>>r[j];
        qq.push_back(r);
    }
    vector<char> ans = f(n,v,q,qq);
    FOR(i,0,q) cout<<ans[i]<<"\n";
}