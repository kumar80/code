#include <bits/stdc++.h>
using namespace std;
#define bug() printf("BUG\n")
#define bug1(n) printf("bg1 %d\n",n)
#define bug2(a,b) printf("bg2 %d %d\n",a,b)
#define MOD 1000000007
#define ll long long
#define vi vector< int >
#define vll vector< long long >
#define vvi vector< vector< int > >
#define vvll vector< vector< long long > >
#define pi pair< int, int >
#define pll pair< long long, long long >
#define vpi vector< pair< int, int > >
#define vpll vector< pair< long long, long long > >
#define pb(n) push_back(n)
#define mp(a,b) make_pair(a,b)
#define printA(a,n) for(int i = 0;i < n;++i) cout<<a[i]<<" "; cout<<endl;
int check5Cond(char s[101][101],int n, int m)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(s[i][j] == '#')
			{
				int temp = 0;
				if(j-1 >= 0 && s[i][j-1] == '#')
					temp++;
				if(j+1 < m && s[i][j+1] == '#')
					temp++;
				if(i-1 >= 0 && s[i-1][j] == '#')
					temp++;
				if(i+1 < n && s[i+1][j] == '#')
					temp++;
				if(temp == 4)
				{
					return 1;
				}
			}
		}
	}
	return 0;
}
void printMap(map< pi,int> mymap)
{
	map< pi,int >::iterator it = mymap.begin();
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		cout << it->first.first<<","<< it->first.second << " => " << it->second << '\n';
}
int checkFor(char s[101][101],int n,int m,int x,int y)
{
//	printf("\n%d %d\n", x,y);
//	printf("BUG1\n");
	int tx,ty;
	pi p;
	stack< pi >st;
	map< pi,int >mymap;
	mymap[mp(x,y)] = 3;
	if(x-1 >= 0 && s[x-1][y] == '#')
	{
		st.push(mp(x-1,y));
		mymap[mp(x-1,y)] = 1;
	}
	else if(x+1 < n && s[x+1][y] == '#')
	{
		st.push(mp(x+1,y));
		mymap[mp(x+1,y)] = 1;
	}
	else if(y-1 >= 0 && s[x][y-1] == '#')
	{
		st.push(mp(x,y-1));
		mymap[mp(x,y-1)] = 1;
	}
	else if(y+1 < m && s[x][y+1] == '#')
	{
		st.push(mp(x,y+1));
		mymap[mp(x,y+1)] = 1;
	}
	while(!st.empty())
	{
		p = st.top();
		st.pop();
		tx = p.first;ty = p.second;
//		printf("%d %d\n", tx,ty);
		if(!(tx == x && ty == y))
		{
			mymap[mp(tx,ty)] = 1;
			if(tx-1 >= 0 && s[tx-1][ty] == '#' && mymap.find(mp(tx-1,ty)) == mymap.end())
				st.push(mp(tx-1,ty));
			if(tx+1 < n && s[tx+1][ty] == '#' && mymap.find(mp(tx+1,ty)) == mymap.end())
				st.push(mp(tx+1,ty));
			if(ty-1 >= 0 && s[tx][ty-1] == '#' && mymap.find(mp(tx,ty-1)) == mymap.end())
				st.push(mp(tx,ty-1));
			if(ty+1 < m && s[tx][ty+1] == '#' && mymap.find(mp(tx,ty+1)) == mymap.end())
				st.push(mp(tx,ty+1));
		}
	}
/*
	printMap(mymap);
	printf("\n");
	printf("BUG2\n");
*/
	if(x-1 >= 0 && s[x-1][y] == '#' && mymap.find(mp(x-1,y)) == mymap.end())
	{
		st.push(mp(x-1,y));
		mymap[mp(x-1,y)] = 2;
	}
	else if(x+1 < n && s[x+1][y] == '#' && mymap.find(mp(x+1,y)) == mymap.end())
	{
		st.push(mp(x+1,y));
		mymap[mp(x+1,y)] = 2;
	}
	else if(y-1 >= 0 && s[x][y-1] == '#' && mymap.find(mp(x,y-1)) == mymap.end())
	{
		st.push(mp(x,y-1));
		mymap[mp(x,y-1)] = 2;
	}
	else if(y+1 < m && s[x][y+1] == '#' && mymap.find(mp(x,y+1)) == mymap.end())
	{
		st.push(mp(x,y+1));
		mymap[mp(x,y+1)] = 2;
	}
	int flag = 0;
	while(!st.empty())
	{
		flag = 1;
		p = st.top();
		st.pop();
		tx = p.first;ty = p.second;
//		printf("%d %d\n", tx,ty);
		if(!(tx == x && ty == y))
		{
			mymap[mp(tx,ty)] = 2;
			if(tx-1 >= 0 && s[tx-1][ty] == '#' && mymap.find(mp(tx-1,ty)) == mymap.end())
				st.push(mp(tx-1,ty));
			if(tx+1 < n && s[tx+1][ty] == '#' && mymap.find(mp(tx+1,ty)) == mymap.end())
				st.push(mp(tx+1,ty));
			if(ty-1 >= 0 && s[tx][ty-1] == '#' && mymap.find(mp(tx,ty-1)) == mymap.end())
				st.push(mp(tx,ty-1));
			if(ty+1 < m && s[tx][ty+1] == '#' && mymap.find(mp(tx,ty+1)) == mymap.end())
				st.push(mp(tx,ty+1));
		}
	}
	if(flag == 0)	
		return 0;
//	printMap(mymap);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
//			if(s[i][j] == '#')
//				printf("%d %d\n%d\n",i,j, mymap[mp(i,j)]);
			if(s[i][j] == '#' /*&& mymap.find(mp(i,j)) == mymap.end()*/ && mymap[mp(i,j)] == 0)
				return 0;
		}
	}
	return 1;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		char s[101][101],ts[101][101];
		int cnt = 0;
		getchar();
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				s[i][j] = getchar();
				ts[i][j] = s[i][j];
				if(s[i][j] == '#')
					cnt++;
			}
			getchar();
		}
		if (cnt < 3)
		{
			printf("-1\n");
			continue;
		}
		if(cnt == 5 && check5Cond(s,n,m))
		{
			printf("3\n");
			continue;
		}
		int temp,flag = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				temp = 0;
				if(j-1 >= 0 && s[i][j-1] == '#')
					temp++;
				if(j+1 < m && s[i][j+1] == '#')
					temp++;
				if(i-1 >= 0 && s[i-1][j] == '#')
					temp++;
				if(i+1 < n && s[i+1][j] == '#')
					temp++;
				if(temp == 1)
				{
					continue;
				}
				if(temp == 4)
				{
					if(j-1 >= 0 && i-1 >= 0 && s[i-1][j-1] == '#')
						temp++;
					if(j-1 >= 0 && i+1 < n && s[i+1][j-1] == '#')
						temp++;
					if(j+1 < m && i-1 >= 0 && s[i-1][j+1] == '#')
						temp++;
					if(j+1 > m && i+1 < n && s[i+1][j+1] == '#')
						temp++;
					if(temp > 6)
						continue;
				}
				if(s[i][j] == '#' && checkFor(s,n,m,i,j))
				{
					flag = 1;
					goto endLoop;
				}
			}
		}
		endLoop:
		{
			if(flag == 1)
				printf("1\n");
			else
				printf("2\n");
		}
	}
	return 0;
}