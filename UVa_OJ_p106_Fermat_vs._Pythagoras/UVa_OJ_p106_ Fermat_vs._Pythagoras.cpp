#include<cstdio>
using namespace std;

int gcd(int n,int m);
int main(void){
	int n;
	while(scanf("%d",&n) != EOF){
		int count=0;
		int p[1000001]={0};
		int z;
		for(int i=2;i*i<n;++i){
			for(int j=1;j<i;++j){
				if((i+j)%2==1 && gcd(i,j) == 1 && (z=i*i+j*j)<=n){
					++count;
					int x=i*i-j*j;
					int y=2*i*j;
					int k=1;
					do{
						p[x*k]=p[y*k]=p[z*k]=1;
					}while(z*(++k) <= n);
				}
			}
		}
		for(int i=n;i>0;--i)
			n-=p[i];
		printf("%d %d\n",count,n);
	}
	return 0;
}

int gcd(int n,int m){
	if(m==0)
		return n;
	else 
		return gcd(m,n%m);
}
