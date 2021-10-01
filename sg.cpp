#include<bits/stdc++.h>
using namespace std;

#define MAXN 100000

int n, t[26][4*MAXN];

void build(int a[], int v, int tl, int tr, int i) {
    if (tl == tr) {
        t[i][v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm,i);
        build(a, v*2+1, tm+1, tr,i);
        t[i][v] = t[i][v*2] + t[i][v*2+1];
    }
}

int sum(int v, int tl, int tr, int l, int r,i) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

int main(){

}