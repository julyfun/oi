#include <bits/stdc++.h>
using namespace std;
int a[100010];
void qs(int l, int r) {
	if (l >= r) return;
	int key = a[(l + r) / 2]; // 任意选择一个数作为 key. 
	int i = l, j = r;
	// 目标是：把所有 <= key 放偏左， >= key 放偏右
	while (i <= j) {
		// 从左往右找到首个 >= key 的数.
		while (a[i] < key && i <= j) i++;
		// 从右往左找到首个 <= key 的数
		while (a[j] > key && i <= j) j--;
		// 此时如果 i <= j，则我们有:
		// * a[i] >= key
		// * a[j] <= key
		// * i <= j，这是一个“左边大，右边小”的情况，只要交换就可以变有序. 
		if (i <= j) { // 如果 i > j，就是“左边小，右边大”的情况，已经有序，不必交换。 
			swap(a[i], a[j]);
			i++; j--;
		}
	}
	// l ~ j 之间 <= key, i ~ r 之间 >= key
	qs(l, j);
	qs(i, r);
}
int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	qs(1, n);
	for (int i = 1; i <= n; i++) cout << a[i] << ' ';
	return 0;
}

