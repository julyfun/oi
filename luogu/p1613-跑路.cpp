#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 51, T = 50;
ll st[N][T + 1];
ll f[N][N];
int main() {
    memset(f, 63, sizeof f);
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        st[u][0] |= (1ll << v);
    }
    for (int t = 1; t <= T; t++)
        for (int u = 1; u <= n; u++) {
            for (int v = 1; v <= n; v++)
                if (st[u][t - 1] & (1ll << v))
                    st[u][t] |= st[v][t - 1];
            for (int v = 1; v <= n; v++)
                if (st[u][t] & (1ll << v))
                    f[u][v] = 1;
        }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    cout << f[1][n] << endl;
    return 0;
}
