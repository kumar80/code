#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define lli long long int
#define FO(i,n) for(int i=0; i<n; i++)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define endl '\n'


int *visibility(int type[], int x[], int a[], vector<pair<int,int>>vec, int h, int n)
{
    int *cnt = new int[2005];
    
    FO(i, n) //i=0 to n-1
    {
        lli numU,denU,numL,denL,numC,denC;
        bool flag=false, flagU=false, flagL=false;
        int xx=vec[i].ff,xx_ind=vec[i].ss;
          cout<<type[xx_ind]<<" "<<xx<<" "<<a[xx_ind]<<": ";

        for(int j=i+1; j<n; j++)
        {
            int xxx=vec[j].ff,xxx_ind=vec[j].ss;
            numC=a[xxx_ind]-a[xx_ind];
            denC=x[xxx_ind]-x[xx_ind];
            if(type[xxx_ind]==0) {
                    if(flagL==false) {
                        if(flagU==false||numC*denU<numU*denC){
                            cnt[xx_ind]++; cnt[xxx_ind]++;
                            cout<<type[xxx_ind]<<" "<<xxx<<" "<<a[xxx_ind];
                            numL=numC;
                            denL=denC;
                        }
                        flagL==true;
                    }
                    else {
                        if(numC*denL>numL*denC && (flagU==false ||numC*denU<numU*denC )){
                            cnt[xx_ind]++; cnt[xxx_ind]++;                
                                         cout<<type[xxx_ind]<<" "<<xxx<<a[xxx_ind];

                        }
                        else if(numC*denL<numL*denC) {
                            numL=numC;
                            denL=denC;
                        }
                    }
                
            }
            else if(type[xxx_ind]==1) {
                    if(flagU==false ){
                        if(flagL==false || numC*denL>numL*denC){
                            cnt[xx_ind]++; cnt[xxx_ind]++;
                            numU=numC;                   
                                      cout<<type[xxx_ind]<<" "<<xxx<<" "<<a[xxx_ind];

                            denU=denC;
                        }
                        flagU=true;
                    }
                    else {
                        if( numC*denU<numU*denC && (flagL==false || numC*denL>numL*denC) ) {
                            cnt[xx_ind]++; cnt[xxx_ind]++;              
                                          cout<<type[xxx_ind]<<" "<<xxx<<" "<<a[xxx_ind];

                        }
                        else if(numC*denU>numU*denC){
                            numU=numC;
                            denU=denC;
                        }
                    }

                    
            }
        }
        
    }

    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while (t--)
    {
        int h,n;
        int type[2005]={0},x[2005]={0},a[2005]={0};
        vector<pair<int,int>>vec;
        cin>>h>>n;
        //vec.clear();
        FO(i,n) {
            cin>>type[i]>>x[i]>>a[i];
            vec.pb(mp(x[i],i));
        }
        sort(all(vec));
        int *cnt=visibility(type, x, a, vec, h, n);
        cout<<t<<": ";
        FO(i,n) cout<<cnt[i]<<" ";
        cout<<endl;
        
    }
    
}