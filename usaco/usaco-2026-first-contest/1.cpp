#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
bool ok(ll d, ll x, ll ca, ll cb, ll b) {
    // 找到最差解
    if (cb <= ca) {
        ll tar_b = b / cb * cb + (cb - 1);
        ll b_in_x = min(x, max(tar_b - b, 0ll));
        ll a_in_x = x - b_in_x;
        ll tot = a_in_x + (b_in_x + b) / cb * ca;
        return tot >= d;
    }
    // 要么全是 b，要么正好分配 some * cb + (cb - 1) 个 b
    ll s1_res = (x + b) / cb * ca;
    ll s2_tar_b = ((x + b) / cb - 1) * cb + (cb - 1);
    ll s2_b_in_x = min(x, max(s2_tar_b - b, 0ll));
    ll s2_a_in_x = x - s2_b_in_x;
    ll s2_res = s2_a_in_x + (s2_b_in_x + b) / cb * ca;
    return min(s1_res, s2_res) >= d;
}
int main() {
    int t; cin >> t;
    while (t--) {
        ll a, b, ca, cb, f; 
        cin >> a >> b >> ca >> cb >> f;
        ll da = f - a;
        if (da <= 0) {
            cout << 0 << "\n";
            continue;
        }
        ll l = 0, r = 1e18, ans = 0;
        while (l <= r) {
            ll mid = (l + r) / 2;
            if (ok(da, mid, ca, cb, b)) {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        cout << ans << "\n";
    }

    return 0;
}
