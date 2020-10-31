#include<bits/stdc++.h>
using namespace std;

int SearchLetter(char *input1, char *input2){
    int l[30]; 
    for(int i=0;i<30;i++) l[i]=0;
    int i= 0; int ans  = -1;
    while(input1[i]!='\0') {
       char c = input1[i];
       l[c-'a']++; int cnt = 0;
        for(int j=0;j<30;j++){
            if( (*input2-'a') == j )  continue;
            if(l[j]) cnt++;                    
        }  
        if(l[*input2-'a']==2) { 
            ans = max(cnt,ans);
            for(int j=0;j<26;j++){
                if( (*input2-'a') == j )  l[j]=1;
                else l[j]=0;
            }  
        }
        i++; 
    }
    return ans;
}
int main(){
        char str[10000];
        cin.get(str, 100);
        char ch; cin>>ch;
        cout<<SearchLetter(str,&ch);
}