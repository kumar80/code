
#include <bits/stdc++.h>
using namespace std;

 
int main()
{

    int t = 1;
  //  cin >> t;
    while (t--)
    {
        vector<string> v = {"GIANT-TEDDY-BEAR", "GIRAFFE", "CAT", "MEGA-BEAR", "DOG", "LION", "BILLY-BEAR", "BESTY-BEAR", "MONKEY", "BOBBY-BEAR", "BUNNY-RABBIT", "BENJAMIN-BEAR", "KUNG-FU-PANDA", "BROWN-BEAR", "PINK-BEAR", "BABY-ELEPHATN", "BLUE-FISH", "HIPPO", "CUTE-PIG", "PIKACHU", "DOREMON", "TORTOISE",
                            "CATER-PILLAR", "CANDY-DOLL"};
        string s;
        cin >> s;  
        int x=0;
            stringstream geek(s); 

          geek>>x;
       // cout << x; 
        if (x >= 1 && x <= 24)
        {
            int j = 1;
            for (int i = 0; i < v.size(); i++)
                if ((i + 1) != x)
                    cout << j++ << "." << v[i] << " ";
        }
        else
        {
            bool ok = false;
            for (int i = 0; i < v.size(); i++)
                if (v[i] == s)
                    ok = true;
            
            if (ok)
            {
                int j = 1;
                for (int i = 0; i < v.size(); i++)
                    if (v[i] != s)
                        cout << j++ << "." << v[i] << " ";
            }
            else if ((x < 1 || x > 24) && isdigit(s[0]))
                cout << "ITEM UNAVAILAIBLE";
            else
                cout << "INTVALID";
        }
    }
}
