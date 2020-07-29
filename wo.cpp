//
// Created by Naman Bhalla on 2019-07-15.
//

#include <bits/stdc++.h>
using namespace std;

//char mat[19][19];
int dp[19][1 << 19][2];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for(int x = 0; x < t; ++x){
//        memset(mat, 0, sizeof mat);
        memset(dp, 0, sizeof dp);

        int n;

        cin >> n;
        vector< string > mat(n + 1);

        for(int i = 1; i <= n; ++i){
            cin >> mat[i];
            mat[i].insert(0, "a");
//            for(int j = 1; j <= n; ++j){
//                cin >> mat[i][j];
//            }
        }

        for(int i = 1; i <= n; ++i){
            for(int j = 0; j < (1 << (n + 1)); ++j){
                for(int l = 0; l < 2; ++l){
                    dp[i][j][l] = dp[i - 1][j][l];
                    if(j & (1 << i)){
                        if(l == 1){
                            if(mat[i][i] == 'C'){
                                dp[i][j][l] = max(dp[i][j][l], 1 + dp[i - 1][j ^ (1 << i)][l ^ 1]);
                            }
                        }
                        for(int k = 1; k < i; ++k){
                            if(mat[i][k] == 'C' and (j & (1 << k))){
                                dp[i][j][l] = max(dp[i][j][l], 1 + dp[i - 1][((j ^ (1 << i)) ^ (1 << k))][l]);
                            }
                        }
                    }
//                    cout << dp[i][j] << " ";
                }
            }
//            cout << endl;
        }


        if(n % 2)
            cout << max(dp[n][((1 << (n + 1)) - 1) ^ 1][0], dp[n][((1 << (n + 1)) - 1) ^ 1][1]) << endl;
        else
            cout << dp[n][((1 << (n + 1)) - 1) ^ 1][0] << endl;


    }

    return 0;
}