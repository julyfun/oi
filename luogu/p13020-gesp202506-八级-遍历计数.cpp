#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10, P = 1e9;
int deg[N];
ll fac[N];
ll pre[N], suf[N];
int main() {
    int n;
    cin >> n;
    fac[0] = 1;
    for (int i = 1; i <= n - 1; i++) {
        int u, v; cin >> u >> v;
        deg[u]++; deg[v]++;
        fac[i] = fac[i - 1] * i % P;
    }
    pre[0] = suf[n + 1] = 1;
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] * fac[deg[i] - 1] % P;
    for (int i = n; i >= 1; i--)
        suf[i] = suf[i + 1] * fac[deg[i] - 1] % P;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans += pre[i - 1] * suf[i + 1] % P * fac[deg[i]] % P;
    cout << ans << endl;
    return 0;
}
