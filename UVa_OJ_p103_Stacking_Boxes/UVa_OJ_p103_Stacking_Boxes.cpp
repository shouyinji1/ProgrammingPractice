#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define LINES 31
#define DIM 10

int k,n;
int box[LINES][DIM];
int max_len=0,path[LINES],path_tmp[LINES],depth[LINES]={0};

bool nest(int a,int b);
void dfs(int origin,int len);

int main(void){
	while(scanf("%d %d",&k,&n) != EOF){
		max_len=0;
		memset(depth,0,sizeof(depth));
		for(int i=1;i<=k;++i){
			for(int j=0;j<n;++j)
				scanf("%d",&box[i][j]);
			sort(&box[i][0],(&box[i][0])+n);
		}
		dfs(0,0);
		printf("%d\n",max_len);
		for(int i=0;i<max_len;++i)
			printf("%d ",path[i]);
		printf("\n");
	}
	return 0;
}

bool nest(int a,int b){
	for(int i=0;i<n;++i)
		if(box[a][i] >= box[b][i])
			return false;
	return true;
}

void dfs(int origin,int len){
	for(int i=1;i<=k;++i){
		if(origin != i && nest(origin,i) && depth[i]<=len){
			depth[i]=len+1;
			path_tmp[len]=i;
			dfs(i,len+1);
		}
	}
	if(max_len < len){
		max_len=len;
		for(int i=0;i<len;++i)
			path[i]=path_tmp[i];
	}
}
