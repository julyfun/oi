#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];
void qs(int a[], int l, int r) {
    if (l >= r)
        return;
    int key = a[(l + r) / 2];
    int i = l, j = r;
    // 小于等于 key 放左边, 大于 key 放右边
    // 任意时刻 i 左边 <= key，j 右边 >= key
    while (i <= j) {
        // 这里不能写 a[i] <= key,
        // 否则若 key 是最大值，则 i 必然一次性走到 r + 1,
        // 导致退出循环时 j = r，无穷递归.
        // 我们只需让 i 和 j 都至少变化一次.
        // 以下写法 i 和 j 必然会在 key 或之前停下来
        // 并交换一次，交换后若 j < i 则 j 与 i 之间是 key.
        while (a[i] < key && i <= j)
            i++;
        // 此时 i 是第一个大于等于 key 的数，或者 i > j
        while (a[j] > key && i <= j)
            j--;
        // 此时 j 是第一个小于等于 key 的数，或者 i > j
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    qs(a, l, j);
    qs(a, i, r);
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    qs(a, 1, n);
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
