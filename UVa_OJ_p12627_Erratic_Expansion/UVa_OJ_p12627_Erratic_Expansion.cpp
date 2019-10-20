#include<cstdio>
using namespace std;

long long c(int k){
	long long t=1;
	while(k--)
		t*=3;
	return t;
}

long long f(int k,int a){
	if(a<=0)
		return 0;
	if(k==0)
		return 1;
	if(a <= 1<<(k-1))
		return 2*f(k-1,a);
	else
		return f(k-1,a-(1<<(k-1)))+2*c(k-1);
}

long long g(int k,int b){
	if(b<=0)
		return 0;
	if(k==0)
		return 1;
	if(b<= 1<<(k-1))
		return g(k-1,b);
	else
		return 2*g(k-1,b-(1<<(k-1)))+c(k-1);
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int k,a,b;
		scanf("%d %d %d",&k,&a,&b);
		printf("Case %d: %lld\n",i,c(k)-f(k,a-1)-g(k,(1<<k)-b));
	}
	return 0;
}
