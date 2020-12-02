#include<bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);         
        for (int i=0;i<n;i++) cin >> a[i];
        int min=*min_element(a.begin(),a.end());
        int ops=0;
        
        for (int i=0;i<n;i++) {
            int nChocs=floor((a[i]-min)/5.0);
            a[i]-=(5*floor((a[i]-min)/5.0));
            ops+=nChocs;
        }
        min=*min_element(a.begin(),a.end()); 
        
        vector <int> freq(5); 
        for (int i=0;i<n;i++) freq[a[i]-min]++; 
        
        int extra_ops=1*(freq[1]+freq[2])+2*(freq[3]+freq[4]);
        
        int extra_ops1=1*(freq[0]+freq[1]+freq[4])+
                          2*(freq[2]+freq[3]);
        if (extra_ops1<extra_ops) extra_ops=extra_ops1;
        
        int extra_ops2=1*(freq[0]+freq[3])+
                          2*(freq[1]+freq[2]+freq[4]);
        if (extra_ops2<extra_ops) extra_ops=extra_ops2;

        cout << ops+extra_ops << endl;
    }
    return 0;
}