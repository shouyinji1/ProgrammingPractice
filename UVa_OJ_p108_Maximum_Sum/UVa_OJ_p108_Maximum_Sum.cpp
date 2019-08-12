#include<cstdio>
using namespace std;

int main(void){
	int m[100][100],n;
	while(scanf("%d",&n) != EOF){
		int max=-127;
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j){
				scanf("%d",&m[i][j]);
				if(max<m[i][j])
					max=m[i][j];
			}
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				for(int k=i;k<n;++k){
					int sum=0;
					for(int c=j;c<n;++c){
						for(int l=i;l<k;++l)
							sum+=m[c][l];
						if(max<sum)
							max=sum;
					}
				}
		printf("%d\n",max);
	}
	
	return 0;
}
