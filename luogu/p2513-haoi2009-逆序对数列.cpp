#include <iostream>
using namespace std;
const int N = 1e3 + 10;
int f[N][N], n, k;
int pre[N][N];
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        f[i][0] = 1;
        for (int j = 1; j <= k; j++) {
            if (j - i < 0)
                f[i][j] = pre[i - 1][j];
            else
                f[i][j] = ((pre[i - 1][j] - pre[i - 1][j - i]) + 10000) % 10000;
        }
        pre[i][0] = 1;
        for (int j = 1; j <= k; j++)
            pre[i][j] = (pre[i][j - 1] + f[i][j]) % 10000;
    }
    cout << f[n][k] << endl;
    return 0;
}
/*
0  1  2  3

1 (i = 1)
1  1
1  2  2  1

*/
