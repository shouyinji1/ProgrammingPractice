#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=510;
int cnt,dis[maxn],q[maxn*10],e[maxn][maxn];

int ed,n;
int vis[maxn];
void BFS(int node,int d){
	int front=1,back=1;
	q[back++]=node;
	vis[node]=true;
	while(front<back){
		node=q[front++];vis[node]=false;
		for(int i=1;i<=n;i++)
			if(e[node][i])
				if(dis[i]<dis[node]+1){
					dis[i]=dis[node]+1;
					if(!vis[i])q[back++]=i;
					vis[i]=true;
				}
	}
	for(int i=1;i<=n;i++)
		if(ed==-1||dis[i]>dis[ed]){
			ed=i;
			printf("%d\n",ed);
		}
}
int main(){
	int a,b,Case=0,st;
	while(scanf("%d",&n)==1&&n){
		scanf("%d",&st);
		for(int i=1;i<=n;i++)dis[i]=0;
		cnt=0;
		memset(e,0,sizeof(e));
		while(~scanf("%d%d",&a,&b)&&a&&b)e[a][b]=1;
		ed=-1;
		BFS(st,0);
		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",++Case,st,dis[ed],ed);
	}
	return 0;
}
