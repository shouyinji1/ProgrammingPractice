/*
2018年第九届蓝桥杯B组JAVA
标题：快速排序
以下代码可以从数组a[]中找出第k小的元素。  
它使用了类似快速排序中的分治算法，期望时间复杂度是O(N)的。
请仔细阅读分析源码，填写划线部分缺失的内容。
*/

import java.util.Random;
public class Main{
	public static int quickSelect(int a[], int l, int r, int k) {
		Random rand = new Random();
		int p = rand.nextInt(r - l + 1) + l;
		int x = a[p];	// 在a中随机选择一个数
		int tmp = a[p]; a[p] = a[r]; a[r] = tmp;	// a[p]<-->a[r]
		int i = l, j = r;
		while(i < j) {
                	while(i < j && a[i] < x) i++;
                	if(i < j) {
                        	a[j] = a[i];
                        	j--;
                	}
                	while(i < j && a[j] > x) j--;
                	if(i < j) {
                        	a[i] = a[j];
                        	i++;
                	}
        	}
        	a[i] = x;
        	p = i;
        	if(i - l + 1 == k) return a[i];
        	if(i - l + 1 < k) return quickSelect( /*______*/ a, i+1, r, k-i+l-1 /*___________*/ ); //填空
        	else return quickSelect(a, l, i - 1, k);	
	}
	public static void main(String args[]) {
		int [] a = {1, 4, 2, 8, 5, 7};
		System.out.println(quickSelect(a, 0, 5, 4));
	}
}

//注意：只提交划线部分缺少的代码，不要抄写任何已经存在的代码或符号。

