#include<iostream>
#include<algorithm>
#include<climits>
#include<cmath>
#include<vector>
#include<map>
#include<stack>
#include<queue>

using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0)
#define ll long long
#define ull unsigned ll
#define pb push_back

#define FOR(i,k,n) for(int i=k; i<n; i++)
#define ROF(i,k,n) for(int i=k; i>=n; i--) 

int svn=7;
int ans;
int backtr(int x, int y, vector< vector<int>> v, string ss, int k , char dir)
{
   // cout<<x<<" x "<<y<<" y "<<k<<" k\n";
    if(k>=48 || x>=7 || y>=7 || x<0 || y<0)
    {
        return 0;
    }    if(v[x][y]==1) {
      return 0;
   }
    if(ss[k]!='?' && dir!=ss[k]) return 0;
    if(x==6 && y==0)
    {
        ans++; return 1;
    }

    v[x][y]=1;
    return ( backtr(x+1,y,v,ss,k+1 , 'U') + backtr(x,y+1,v,ss,k+1, 'R') + backtr(x-1,y,v,ss,k+1, 'D') + backtr(x,y-1,v,ss,k+1, 'L') );
}
int main()
{
    //fastio;

    string ss; cin>>ss;
    vector< vector<int>> v(svn,vector<int>(svn,0));
    ans=0;
  
    cout<<backtr(0,0,v,ss,0, '?');
    
    
    return 0;
}