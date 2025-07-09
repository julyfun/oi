#include <iostream>
#include <vector>
#include <set>
typedef unsigned long long ll;
using namespace std;
ll n, m, c, k;
vector<ll> needs[100];
set<ll> r;
int main() {
    cin >> n >> m >> c >> k;
    // 动物 |: 10000110 ->
    // .............0101000001101011100
    // check 64 bits
    ll all = 0;
    for (int i = 1; i <= n; i++) {
        ll a; cin >> a;
        all |= a;
    }
    for (int i = 1; i <= m; i++) {
        ll p, q; cin >> p >> q;
        needs[p].push_back(q);
    }
    for (ll t = 0; t <= k - 1; t++)
        if (all & (1ull << t))
            for (auto q: needs[t])
                r.insert(q);
    ll ans = 1;
    for (ll t = 0; t <= k - 1; t++) {
        bool ok = 1;
        for (auto q: needs[t])
            if (r.count(q) == 0)
                ok = 0;
        if (ok)
            ans <<= 1ll;
    }
    if (ans == 0 && n == 0) cout << "18446744073709551616\n";
    else cout << ans - n << endl;
    return 0;
}
