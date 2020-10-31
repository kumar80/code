                       
#include<bits/stdc++.h>
using namespace std;
 
int main(){

        string s; cin>>s; char ch; cin>>ch;
        int n = s.size();
        transform(s.begin(), s.end(), s.begin(), ::tolower); 

        vector<int>v(30,0); int ans = -1;
        for(int i=0;i<n;i++){
            v[s[i]-'a']++; int cnt=0; 
            for(int j=0;j<30;j++){
                    if( (ch-'a') == j )  continue;
                    if(v[j]) cnt++;                    
            }  
            if(v[ch-'a']==2) { 
                ans = max(cnt,ans);
                for(int j=0;j<26;j++){
                    if( (ch-'a') == j )  v[j]=1;
                    else v[j]=0;
                }  
            } 
        }
        cout<<ans;
    
}
