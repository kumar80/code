#include <bits/stdc++.h>
using namespace std;

float findWater(int i, int j,float k)
{
     
 
    float dp[i+1][2*i + 1];
    bool vis[i+1][2*i + 1];
     
    for(int n=0;n<i+1;n++)
    {
        for(int m=0;m<(2*i+1);m++)
        {
            dp[n][m] = 0;
            vis[n][m] = false;
        }
    }
     
    queue<pair<int,int>>q;
    dp[0][i] = k;
     

    q.push({0,i});
    vis[0][i] = true;
     
    while(!q.empty())
    {
        pair<int,int>temp = q.front();
        q.pop();
        int n = temp.first;
        int m = temp.second;
         
        if(i == n)
            break;
             
             
        float x = dp[n][m];
        if(float((x-1.0)/2.0) < 0)
        {
            dp[n+1][m-1] += 0;
            dp[n+1][m+1] += 0;
        }
        else
        {
            dp[n+1][m-1] += float((x-1.0)/2.0);
            dp[n+1][m+1] += float((x-1.0)/2.0);    
        }
        if(vis[n+1][m-1]==false)
        {
            q.push({n+1,m-1});
            vis[n+1][m-1] = true;
        }
        if(vis[n+1][m+1]==false)
        {
            q.push({n+1,m+1});
            vis[n+1][m+1] = true;
        }
    }
    
    if(dp[i-1][2*j-1]>1)
        dp[i-1][2*j-1] = 1.0;
         
     
    return dp[i-1][2*j-1];
 
}
int main(){
    int i,j; cin>>i>>j;
    float x; cin>>x;
    cout<<findWater(i,j,x);
}