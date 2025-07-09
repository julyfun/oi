#include <iostream>
using namespace std;
int n;
bool used[10010];
int ans = 0;
void dfs(int n, int sum) {
    if (n == 0) {
        if (!used[sum])
            used[sum] = 1, ans++;
        return;
    }
    for (int i = 1; i <= n; i++) {
        dfs(n - i, sum + i * (i - 1) / 2);
    }
}
int main() {
    cin >> n;
    dfs(n, 0);
    cout << ans << endl;
    return 0;
}
