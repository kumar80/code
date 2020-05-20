#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int n = prices.size();
    bool buy=true,sell=false;
    int p = 0;
    for(int i=1;i<n;i++){
    if(buy){
    if(prices[i-1]>=prices[i]) continue;
    p+=-prices[i-1];
    buy=false; sell=true;
    }
    if(sell){
    if(prices[i-1]<=prices[i]) continue;
    p+=prices[i-1];
    buy=true; sell = false;    
    }
    }
    return p;
};