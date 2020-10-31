#include<cstring>
#include<cstdio>
#include<algorithm>
#define fo(i,a,b) for(int i=a,__=b;i<=__;++i)
#define N 9010
#define mo 1000000007
using namespace std;
int f[N][N],n,m,q,k,x[N],y[N],use[N];
struct lim{int x,y;}l[N];
bool cmp(lim a,lim b){return a.y<b.y;}
int main(){
	int _;
	scanf("%d",&_);
	while(_--){
		scanf("%d %d %d",&n,&m,&k);
		fo(i,1,m)scanf("%d %d",x+i,y+i);
		scanf("%d",&q);
		fo(i,1,q)scanf("%d %d",&l[i].x,&l[i].y);
		sort(l+1,l+q+1,cmp);
		fo(i,0,k)fo(j,0,n)f[i][j]=0;f[0][1]=1;
		fo(i,1,n)use[i]=-1;
		int p=1;
		fo(i,0,k-1){
			int P=0;
			while(p<=q&&l[p].y==i){
			fo(j,1,n)if(j^l[p].x)f[i][j]=0;
				++p;
			}
			fo(j,1,n)f[i+1][j]=(f[i+1][j]+f[i][j])%mo;
			fo(j,1,m){
				f[i+1][y[j]]=(f[i+1][y[j]]+f[i][x[j]])%mo;
				f[i+1][x[j]]=(f[i+1][x[j]]+f[i][y[j]])%mo;
			}
		}
		int P=0;
		while(p<=q&&l[p].y==k){
		fo(j,1,n)if(j^l[p].x)f[k][j]=0;++p;
		}
		int ans=0;
		fo(i,1,n)ans=(ans+f[k][i])%mo;
		printf("%d\n",ans);
	}
}