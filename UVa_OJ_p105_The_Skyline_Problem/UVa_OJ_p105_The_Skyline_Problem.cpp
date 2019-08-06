#include<cstdio>
using namespace std;

int main(void){
	int skyline[10000]={0};
	int L,H,R;
	int rightest=0;
	while(scanf("%d %d %d",&L,&H,&R) != EOF){
		for(;L<R;++L)
			if(H > skyline[L])
				skyline[L]=H;
		if(R > rightest)
			rightest = R;
	}
	for(int i=1;i<=rightest;++i)
		if(skyline[i-1] != skyline[i]){
			printf("%d %d",i,skyline[i]);
			if(i != rightest)
				printf(" ");
		}
	printf("\n");
	return 0;
}
