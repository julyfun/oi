#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll P = 1e9 + 7;
const int M = 1e5 + 10;
struct L {
    int c, d;
} l[M];
int n, m, v;
ll qpow(ll a, ll b) {
    ll base = a, res = 1;
    while (b) {
        if (b & 1ll) res = res * base % P;
        base = base * base % P;
        b >>= 1;
    }    
    return res;
}
ll mod(ll x) {
    return (x % P + P) % P;
}
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n >> m >> v;
        for (int i = 1; i <= m; i++)
            cin >> l[i].c >> l[i].d;
        sort(l + 1, l + m + 1, [](L a, L b) { return a.c < b.c; });
        ll free = n - 1;
        bool bad = false;
        ll ans = 1;
        for (int i = 2; i <= m; i++) {
            if (l[i].c == l[i - 1].c) {
                if (l[i].d != l[i - 1].d) {
                    bad = true;
                    cout << 0 << '\n';
                    break;
                }
                continue;
            }
            ll cnt = l[i].c - l[i - 1].c;
            free -= cnt;
            ans = ans * mod(qpow(v, cnt * 2) - qpow(v, cnt - 1) * (v - 1)) % P;
        }
        if (bad) continue;
        ans = ans * qpow(v, free * 2) % P;
        cout << ans << '\n';
    }

    return 0;
}
