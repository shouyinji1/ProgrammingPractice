/* 2019年蓝桥杯程序设计省赛B组：试题D、数的分解
 * 问题描述：
 * 把2019分解成3个各不相同的正整数之和，并且要求每个正整数都不包含数字2和4，一共有多少种不同的分解方法？
 * 注意交换3个整数的顺序被视为同一种方法，例如1000+1001+18和1001+1000+18被视为同一种。
 * */


#include<cstdio>

using namespace std;

// 判断是否包含数字2或4
// 包含为false，不包含为true
bool judge(int n){
	while(n){
		if(n%10==2 || n%10==4)
			return false;
		n/=10;
	}
	return true;
}

int main(){
	int count=0;
	for(int i=1;i<2019;++i)
		if(judge(i))
			for(int j=i+1;j<2019;++j)
				if(judge(j))
					for(int k=j+1;k<2019;++k)
						if(judge(k) && i+j+k==2019)
							++count;
	printf("%d\n",count);
	return 0;
}
