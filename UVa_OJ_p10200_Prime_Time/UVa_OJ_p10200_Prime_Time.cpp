#include<cstdio>
using namespace std;
int isPrime(int n){
	for(int i=2;i*i<=n;i++)
		if(n % i == 0)
			return 0;
	return 1;
}
int main(void){
	int a,b;
	int is_prime[10001]={1};
	for(int i=1;i<=10000;i++)
		is_prime[i]=isPrime(i*i+i+41);
	while(scanf("%d %d",&a,&b) != EOF){
		int count=0;
		for(int i=a;i<=b;i++)
			count+=is_prime[i];
		printf("%.2lf\n",count*100.0/(b-a+1)+1e-6);
	}
	return 0;
}
