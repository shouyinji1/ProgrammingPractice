#include<cstdio>
#include<vector>
using namespace std;

vector<int> block[25];
int pos[25];

void returnInitial(int a);
void pile(int a,int b);
void print(int n);

int main(){
	int n,a,b;
	char op1[5],op2[5];
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		block[i].push_back(i);
		pos[i]=i;
	}
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
	int trail=(int)block[p].size();
	while((tmp=block[p][--trail]) != a){
		block[tmp].push_back(tmp);
		pos[tmp]=tmp;
		block[tmp].resize(1);
	}
	block[p].resize(trail+1);
}

void pile(int a,int b){
	int p=pos[a],p_b=pos[b];
	int trail_p=(int)block[p].size();
	int tmp,i=0;
	while(block[p][i] != a)
		++i;
	tmp=i;
	while(i<trail_p){
		pos[block[p][i]]=p_b;
		block[p_b].push_back(block[p][i++]);
	}
	block[p].resize(tmp);
}

void print(int n){
	for(int i=0;i<n;++i){
		int trail=(int)block[i].size();
		printf("%d:",i);
		for(int j=0;j<trail;++j)
			printf(" %d",block[i][j]);
		printf("\n");
	}
}
