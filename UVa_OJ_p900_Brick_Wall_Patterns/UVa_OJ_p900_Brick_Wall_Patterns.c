#include<stdio.h>
int main(void){
	int n;
	long fibonacci[51];
	int i;
	fibonacci[1]=1L;
	fibonacci[2]=2L;
	for(i=3;i<=50;i++)
		fibonacci[i]=fibonacci[i-1]+fibonacci[i-2];
	while(scanf("%d",&n),n)
		printf("%ld\n",fibonacci[n]);
	return 0;
}

