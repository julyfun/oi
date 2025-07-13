#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a[210];
int f[210][210], g[210][210], pre[210];
int main() {
    int n;
    cin >> n;
    memset(g, 63, sizeof(g));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
        f[i][i] = f[i + n][i + n] = g[i][i] = g[i + n][i + n] = 0;
    }
    for (int i = 1; i <= n; i++)
        pre[i + n] = pre[i + n - 1] + a[i];
    for (int d = 2; d <= n; d++)
        for (int l = 1; l + d - 1 <= 2 * n; l++) { // 开头在 n 之后的可能成为答案的一部分.
            int r = l + d - 1;
            for (int mid = l; mid <= r - 1; mid++) {
                f[l][r] = max(f[l][r], f[l][mid] + f[mid + 1][r] + pre[r] - pre[l - 1]);
                g[l][r] = min(g[l][r], g[l][mid] + g[mid + 1][r] + pre[r] - pre[l - 1]);
            }
        }
    int a1 = 0, a2 = 0x7fffffff;
    for (int i = 1; i <= n; i++) {
        a1 = max(a1, f[i][i + n - 1]);
        a2 = min(a2, g[i][i + n - 1]);
    }
    cout << a2 << '\n' << a1 << endl;
    return 0;
}
