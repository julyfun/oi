#include <iostream>
#include <algorithm>
using namespace std;
int n, a[1010], ans = 0, c, b[1010];
void dfs(int pos, int cnt, int sum) {
    if (sum > c) return;
    if (sum >= ans) ans = sum;
    if (pos == n + 1) return;
    dfs(pos + 1, cnt, sum);
    if (cnt >= 3 && a[pos] < b[cnt - 1] + b[cnt - 2]) return;
    b[cnt] = a[pos];
    dfs(pos + 1, cnt + 1, sum + a[pos]);
}
int main() {
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    dfs(1, 0, 0);
    cout << ans << endl;
    return 0;
}
