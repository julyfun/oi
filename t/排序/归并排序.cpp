#include <bits/stdc++.h>
using namespace std;
int a[100010];
int c[100010];
void ms(int l, int r) {
	if (l == r) return;
	int mid = (l + r) / 2;
	ms(l, mid);
	ms(mid + 1, r);
	int i = l, j = mid + 1;
	int cnt = l;
	// 例: 六个数 1 3 4 | 2 5 6，先把 1 放到 c 的开头，再把 2 放到 c 的开头.. 
	while (i <= mid && j <= r) {
		if (a[i] < a[j]) // 判断左序列的开头和右序列的开头哪个更小.
			c[cnt++] = a[i++];
		else
			c[cnt++] = a[j++];
	}
	while (i <= mid) // 此时左序列和右序列必有一个还没取完，直接放到 c 最后面.
		c[cnt++] = a[i++];
	while (j <= r)
		c[cnt++] = a[j++];
	// 此时 a 的左半边没动过，右半边也没动过， 
	// c 的对应位置是左半边和右半边排好序的结果
	for (int i = l; i <= r; i++)
		a[i] = c[i];
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	ms(1, n);
	for (int i = 1; i <= n; i++) cout << a[i] << ' ';
	return 0;
}
