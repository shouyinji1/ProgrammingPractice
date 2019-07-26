#include<cstdio>
using namespace std;

int main(void){
	int b1,g1,c1,b2,g2,c2,b3,g3,c3;
	char bin[6][4]={"BCG","BGC","CBG","CGB","GBC","GCB"};
	while(scanf("%d %d %d %d %d %d %d %d %d",&b1,&g1,&c1,&b2,&g2,&c2,&b3,&g3,&c3) != EOF){
		int min[6],m=0;	
		min[0]=b2+b3+c1+c3+g1+g2;
		min[1]=b2+b3+g1+g3+c1+c2;
		min[2]=c2+c3+b1+b3+g1+g2;
		min[3]=c2+c3+g1+g3+b1+b2;
		min[4]=g2+g3+b1+b3+c1+c2;
		min[5]=g2+g3+c1+c3+b1+b2;

		for(int i=1;i<6;++i)
			if(min[i]<min[m]) 
				m=i;
		printf("%s %d\n",bin[m],min[m]);
	}
	return 0;
}
