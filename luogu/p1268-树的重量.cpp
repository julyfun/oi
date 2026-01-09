// tags: 树形数据结构, 枚举, 构造
// 考虑加入第 i 个点时，新边的长度怎么算
// 任取 j, k，如果 i 是 j, k 的链上延伸出来的
// 那么新边长度就是 ((j, k) + (i, k) - (j, i)) / 2.
// 如果不是延伸出来的，上述公式会大于实际新边.
// 取 1 号点作为链的一端，对于所有链取上述公式最小值即可.
#include <bits/stdc++.h>
using namespace std;
int a[32][32];
int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n - i; j++)
            cin >> a[i][j + i];
    int ans = a[1][2];
    for (int i = 3; i <= n; i++) {
        int mi = 1e9;
        for (int j = 2; j < i; j++)
            mi = min(mi, (a[1][i] + a[j][i] - a[1][j]) / 2);
        ans += mi;
    }
    cout << ans << "\n";
    return 0;
}
