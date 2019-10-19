#include<cstdio>
#include<queue>
using namespace std;

struct Point{
	char x,y;
	int step;
	Point(char x,char y,int step):x(x),y(y),step(step){}
};
char sou[3],des[3];
int dx[]={-1,-2,-1,-2, 1, 2,1,2};
int dy[]={-2,-1, 2, 1,-2,-1,2,1};

int bfs(){
	Point p(sou[0],sou[1],0);
	queue<Point> q;
	q.push(p);
	while(!q.empty()){
		Point f=q.front();
		if(f.x==des[0] && f.y==des[1])
			return f.step;
		q.pop();
		for(int i=0;i<8;++i)
			if(f.x+dx[i]>='a' && f.y+dy[i]>='1' && f.x+dx[i]<='h' && f.y+dy[i]<='8')
				q.push(Point(f.x+dx[i],f.y+dy[i],f.step+1));
	}
	return -1;
}

int main(){
	while(~scanf("%s %s",sou,des))
		printf("To get from %s to %s takes %d knight moves.\n",sou,des,bfs());
	return 0;
}
