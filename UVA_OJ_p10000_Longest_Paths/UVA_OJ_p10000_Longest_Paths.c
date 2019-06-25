#include <stdio.h>
int main(void){
	int n;
	int Case=0;
	while(scanf("%d",&n),n){
		int arr[101][101]={{0}};
		int s;
		int p,q;
		int i,j,k;
		scanf("%d",&s);
		while(scanf("%d %d",&p,&q),(p && q))
			arr[p][q]=1;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				for(k=1;k<=n;k++)
					if(arr[i][j] && arr[j][k] && arr[i][k]<arr[i][j]+arr[j][k])
						arr[i][k]=arr[i][j]+arr[j][k];
		int max_len=0;
		int des=s;
		for(i=1;i<=n;i++)
			if(arr[s][i]>max_len){
				max_len=arr[s][i];
				des=i;
			}
		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",++Case,s,max_len,des);
	}
	return 0;
}
