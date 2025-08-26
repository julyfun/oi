#include <iostream>
using namespace std;
typedef long long ll;
const int N = 35;
int n;
int a[N];
ll f[N][N];
int root[N][N];
void dfs(int rt, int l, int r) {
    if (rt == 0) return;
    cout << rt << " ";
    dfs(root[l][rt - 1], l, rt - 1);
    dfs(root[rt + 1][r], rt + 1, r);
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int d = 1; d <= n; d++)
        for (int l = 1; l + d - 1 <= n; l++) {
            int r = l + d - 1;
            for (int rt = l; rt <= r; rt++) {
                ll ls = 0, rs = 0;
                if (l == r) {
                    f[l][r] = a[rt];
                    root[l][r] = rt;
                    continue;
                }
                if (rt == l) ls = 1;
                else ls = f[l][rt - 1];
                if (rt == r) rs = 1;
                else rs = f[rt + 1][r];
                if (f[l][r] < ls * rs + a[rt]) {
                    f[l][r] = ls * rs + a[rt];
                    root[l][r] = rt;
                }
            }
        }
    cout << f[1][n] << endl;
    dfs(root[1][n], 1, n);
    return 0;
}

