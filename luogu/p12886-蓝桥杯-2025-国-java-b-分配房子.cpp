#include <iostream>
using namespace std;
typedef long long ll;
ll P = 1e9 + 7;
ll qp(ll a, ll b) {
    ll base = a, ans = 1;
    while (b) {
        if (b & 1) (ans *= base) %= P;
        (base *= base) %= P;
        b >>= 1;
    }
    return ans;
}
ll inv(ll a) {
    return qp(a, P - 2);
}
int main() {
    // C 20255202 - 1, 5202 / 2
    ll ans = 2;
    for (ll i = 20255202 - 1; i >= 20255202 - 5202 / 2; i--)
        ans = ans * i % P;
    for (ll i = 1; i <= 5202 / 2; i++)
        ans = ans * inv(i) % P;
    cout << ans << endl;
    return 0;
}
