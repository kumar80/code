#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

int x[110],y[110];
bool graph[110][110];

int main(void){
    int N,i,j,k;
    int t; cin>>t;
while(t--){    cin >> N;
    REP(i,N) cin >> x[i] >> y[i];
    
    REP(i,N) graph[i][i] = true;
    REP(i,N) REP(j,N) if(x[i] == x[j] || y[i] == y[j]) graph[i][j] = graph[j][i] = true;
    REP(k,N) REP(i,N) REP(j,N) if(graph[i][k] && graph[k][j]) graph[i][j] = true;
    
    int comp = 0;
    REP(i,N){
        bool root = true;
        REP(j,i) if(graph[i][j]) root = false;
        if(root) comp++;
    }
    
    cout << comp - 1 << endl;}
    
    return 0;
}
