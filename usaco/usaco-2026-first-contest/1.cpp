#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
    int t; cin >> t;
    while (t--) {
        ll a, b, ca, cb, f; 
        cin >> a >> b >> ca >> cb >> f;
        if (f - (a + b / cb * ca) <= 0) {
            cout << 0 << "\n";
            continue;
        }
        // 刚好无法兑换 a
        ll b1 = b / cb * cb + (cb - 1);
        ll s1 = b1 - b + (f - (b / cb) * ca - a);
        
        // 全部投入 b
        ll s2 = ((f - a - 1) / ca + 1) * cb - b;
        
        // 刚好不够兑换足够的 a
        ll b3 = (f - a - 1) / ca * cb + (cb - 1);
        ll s3 = (b3 - b) + (f - a) - b3 / cb * ca;
        cout << max(0ll, max(s1, max(s2, s3))) << "\n";
    }

    return 0;
}
