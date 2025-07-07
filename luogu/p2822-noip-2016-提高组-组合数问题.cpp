#include <iostream>
using namespace std;
const int N = 2e3 + 10, M = 2000;
int d[N][N];
int sum[N][N];
int main() {
    int t, k;
    cin >> t >> k;
    for (int i = 0; i <= M; i++)
        d[i][0] = 1;
    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= i; j++)
            d[i][j] = (d[i - 1][j - 1] + d[i - 1][j]) % k;
    for (int i = 0; i <= M; i++) {
        sum[i][0] = d[i][0] == 0;
        for (int j = 1; j <= i; j++)
            sum[i][j] = sum[i][j - 1] + (d[i][j] == 0);
    }
    while (t--) {
        int n, m; cin >> n >> m;
        int ans = 0;
        for (int i = 0; i <= n; i++)
            ans += sum[i][min(i, m)];
        cout << ans << endl;
    }
    return 0;
}
