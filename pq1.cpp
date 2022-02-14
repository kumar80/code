#include <bits/stdc++.h>
using namespace std;
void solve()
{
    
   long long x=rand()%100;
   vector<int>a(3);

    if(x%2)
    {
       if(x==1)
        {
           // cout<<"1"<<" 2"<<" 4\n";
           a[0]=1,a[1]=2,a[2]=4; 
           // return; 11  110 101 
        }else 
      // cout<<"1"<<" "<<x-1<<" "<<x<<endl;
            a[0]=1,a[1]=x-1,a[2]=x;
    }
    else
    {
        if(x==2)
        {//11 9 10
            //cout<<"1 6 2\n";
            a[0]=1,a[1]=6,a[2]=2;
           // return;
        }else
       // cout<<2<<" "<<x+1<<" "<<x<<endl;
        a[0]=2,a[1]=x+1,a[2]=x;
    }
    if(( (a[0] | a[1]) & (a[1] | a[2]) & (a[0] | a[2])) != x)  {
        cout<<x<<"\n"<<a[0]<<" "<<a[1]<<" "<<a[2]<<"\n"<<( (a[0] | a[1]) & (a[1] | a[2]) & (a[0] | a[2])) <<"\n";
    }
}

int main() {
    int test=1000000;
   // cin>>test;
    while(test--)
    solve();
 return 0;
}