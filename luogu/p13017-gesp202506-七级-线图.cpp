#include <iostream>
typedef long long ll;
using namespace std;
const int N = 1e5 + 10;
int in[N];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        in[u]++; in[v]++;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += ll(in[i]) * ll(in[i] - 1) / 2ll;
    }
    cout << ans << endl;
    return 0;
}
