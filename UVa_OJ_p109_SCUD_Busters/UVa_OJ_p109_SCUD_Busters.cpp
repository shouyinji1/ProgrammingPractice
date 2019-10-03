#include<bits/stdc++.h>
using namespace std;

struct P{
	int x, y;
	P(int x = 0, int y = 0): x(x), y(y) {}
	bool read(){
		return ~scanf("%d%d", &x, &y);
	}
	bool operator < (const P& p) const{	///加cosnt以便sort调用，其他函数不加const对速度没有影响
		return x < p.x || x == p.x && y < p.y;
	}
	P operator + (P p){
		return P(x + p.x, y + p.y);
	}
	P operator - (P p){
		return P(x - p.x, y - p.y);
	}
	int dot(P p){
		return x * p.x + y * p.y;
	}
	int det(P p){
		return x * p.y - y * p.x;
	}
} a[105], ans[25][105];

int n, len, Size[25];
bool vis[25];

// Graham扫描法求凸包
void convex_hull(int country){
	sort(a, a + n);
	len = 0;
	int i;
	for (i = 0; i < n; ++i){
		while(len>=2 && (ans[country][len-1]-ans[country][len-2]).det(a[i]-ans[country][len-1])<=0)
			--len;
		ans[country][len++] = a[i];
	}
	int tmp = len;
	for (i = n - 2; i >= 0; --i){
		while(len>tmp && (ans[country][len-1]-ans[country][len-2]).det(a[i]-ans[country][len-1])<=0)
			--len;
		ans[country][len++] = a[i];
	}
	--len;
	ans[country][len] = ans[country][0]; ///ok
	Size[country] = len;
}

///点q在线段p1p2上
inline bool on_seg(P p1, P p2, P q){
	return (p1 - q).det(p2 - q) == 0 && (p1 - q).dot(p2 - q) <= 0;
}

// 判断点q在country内，这种方法仅适用于凸包
bool in_area(int country, P q){
	int cnt = 0, k, d1, d2;
	for (int i = 0; i < Size[country]; ++i){
		if (on_seg(ans[country][i], ans[country][i + 1], q)) return false;
		k = (ans[country][i + 1] - ans[country][i]).det(q - ans[country][i]);
		d1 = ans[country][i].y - q.y;
		d2 = ans[country][i + 1].y - q.y;
		if (k > 0 && d1 <= 0 && d2 > 0) ++cnt;
		if (k < 0 && d1 > 0 && d2 <= 0) --cnt;
	}
	return cnt != 0;
}

int area(int country){
	int sum = 0;
	for (int i = 0; i < Size[country]; ++i)
		sum += ans[country][i].det(ans[country][i + 1]);
	return sum;
}

int main(){
	int country = 0, i;
	for (; scanf("%d", &n), n > 0; ++country){
		for (i = 0; i < n; ++i) a[i].read();
		convex_hull(country);
	}
	int sumA = 0;
	P p;
	while (p.read())
		for (i = 0; i < country; ++i)
			if (!vis[i] && in_area(i, p)){
				vis[i] = true;
				sumA += area(i);
			}
	if (sumA & 1) printf("%d.50\n", sumA >> 1);
	else printf("%d.00\n", sumA >> 1);
	return 0;
}
