#include<cstdio>
using namespace std;

int block[25][25];
int pos[25];
int trail[25]={0};
int temp[25];

void returnInitial(int a);
void pile(int a,int b);
void print(int n);

int main(){
	int n,a,b;
	char op1[5],op2[5];
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		block[i][0]=pos[i]=i;
	while(scanf("%s",op1),op1[0] != 'q'){
		scanf("%d %s %d",&a,op2,&b);
		if(pos[a] == pos[b])
			continue;
		if(op1[0]== 'm')
			returnInitial(a);
		if(op2[1] == 'n')
			returnInitial(b);
		pile(a,b);
	}
	print(n);
	return 0;
}

void returnInitial(int a){
	int tmp,p=pos[a];
	while((tmp=block[p][trail[p]]) != a){
		block[tmp][0]=pos[tmp]=tmp;
		trail[tmp]=0;
		--trail[p];
	}
}

void pile(int a,int b){
	int p=pos[a],p_b=pos[b];
	int i=0;
	while((temp[i++]=block[p][trail[p]--]) != a);
	while(i)
		pos[block[p_b][++trail[p_b]]=temp[--i]]=p_b;
}

void print(int n){
	for(int i=0;i<n;++i){
		printf("%d:",i);
		for(int j=0;j<=trail[i];++j)
			printf(" %d",block[i][j]);
		printf("\n");
	}
}
