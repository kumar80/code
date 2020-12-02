#include<bits/stdc++.h>
#define pn() printf("\n")
#define si(x) scanf("%d",&x)
#define pi(x) printf("%d\n",x)
#define sll(x) scanf("%lld",&x)
#define pll(x) printf("%lld\n",x)
#define sc(x) scanf("%c",&x)
#define pc(x) printf("%c",x)
#define sf(x) scanf("%f",&x)
#define pf(x) printf("%f\n",x)
#define sd(x) scanf("%lf",&x)
#define pd(x) printf("%.7lf\n",x)
#define sld(x) scanf("%Lf",&x)
#define pld(x) printf("%.9Lf\n",x)
#define MOD 1000000007
#define ll long long
using namespace std;
ll cnt[16];
void process(ll x){
    bool has[4];
    memset(has,false,sizeof(has));
    while(x){
        int last=x%10;
        if(last==2){
            has[0]=true;
        }
        if(last==3){
            has[1]=true;
        }
        if(last==5){
            has[2]=true;
        }
        if(last==7){
            has[3]=true;
        }
        x/=10;
    }
    for(int i=1;i<=15;i++){
        bool flag=true;
        for(int j=0;j<4;j++){
            if(i&(1<<j)){
                if(!has[j]){
                    flag=false;
                }
            }
        }
        if(flag){
            cnt[i]++;
        }
    }
}
ll ch3(ll n){
 
        return (n*(n-1)*(n-2))/6;
 
}
int main(void){
    memset(cnt,0,sizeof(cnt));
    int n;
    cin>>n;
    ll x;
    for(int i=1;i<=n;i++){
        cin>>x;
        process(x);
    }
    ll ans=0;
    for(int i=1;i<=15;i++){
        int bits=__builtin_popcount(i);
        if(bits&1){
            ans+=ch3(cnt[i]);
        }
        else{
            ans-=ch3(cnt[i]);
        }
    }
    cout<<ans;
    return 0;
}