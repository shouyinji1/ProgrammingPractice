/* *
 * Question: 判断一个数字n是否是若干个2050拼起来的
 * */

#include<iostream>
#include<string>
using namespace std;

int main(){
	string str;
	cin >> str;
	int str_size=str.size();
	bool is2050=true;
	if(str_size%4 == 0){
		for(int i=0;i<str_size;++i){
			if(str[i] !='2' || 
					str[++i] !='0' ||
					str[++i] !='5' || 
					str[++i] !='0'){
				is2050=false;
				break;
			}
		}
	}

	if(is2050)
		cout << "是若干个2050拼凑起来的" << endl;
	else
		cout << "不是若干个2050拼凑起来的" << endl;
	return 0;
}
