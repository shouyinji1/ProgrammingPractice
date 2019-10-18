#include<cstdio>
using namespace std;

char a[102][102]={{0}};
void dfs(int row,int column);

int main(void){
	int m,n;
	while(scanf("%d %d",&m,&n) && m){
		int count=0;
		for(int i=1;i<=m;++i){	// Input
			getchar();
			for(int j=1;j<=n;++j)
				scanf("%c",&a[i][j]);
		}
		for(int i=1;i<=m;++i)	// Find
			for(int j=1;j<=n;++j)
				if(a[i][j]=='@'){
					count++;
					dfs(i,j);
				}
		printf("%d\n",count);
	}
	return 0;
}

void dfs(int row,int column){
	for(int i=-1;i<=1;++i)
		for(int j=-1;j<=1;++j){
			int row_i=row+i,column_j=column+j;
			if(a[row_i][column_j] == '@'){
				a[row_i][column_j]='*';
				dfs(row_i,column_j);
			}
		}
}
