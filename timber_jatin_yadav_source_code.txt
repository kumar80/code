#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<", "<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"{";
	for(int i = 0;i < (int)v.size(); i++){
		if(i)os<<", ";
		os<<v[i];
	}
	os<<"}";
	return os;
}

#ifdef LOCAL
#define cerr cout
#endif

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

void solve(){
	int n; 
    sd(n);
    map<int, vector<int>> lft, rgt;
    vector<int> pts;
    for(int i = 0; i < n; i++){
        int p, h;
        scanf("%d %d", &p, &h);
        pts.push_back(p);
        pts.push_back(p + h);
        pts.push_back(p - h);
        rgt[p + h].push_back(h);
        lft[p - h].push_back(h);
    }
    sort(all(pts));
    pts.erase(unique(all(pts)), pts.end());
    map<int, int> dp_lft, dp_rgt;
    for(int x : pts){
        for(int h : rgt[x]) dp_rgt[x] = max(dp_rgt[x], dp_rgt[x - h] + h);
    }

    reverse(all(pts));

    int ans = 0;

    for(int x : pts){
        for(int h : lft[x]) dp_lft[x] = max(dp_lft[x], dp_lft[x + h] + h);
        ans = max(ans, dp_lft[x] + dp_rgt[x]);
    }

    printf("%d\n", ans);
}

int main(){
	int t; sd(t);
	for(int tt = 1; tt <= t; tt++){
		printf("Case #%d: ", tt);
		solve();
	}
}