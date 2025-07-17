#include <iostream>
using namespace std;
typedef unsigned long long ll;
int main() {
    ll n, k;
    cin >> n >> k;
    for (int i = n - 1; i >= 0; i--) {
        // cout << k << endl;
        bool v = k & (1ull << i);
        cout << v;
        ll t = 0;
        if (i != 63) t = 1ull << (i + 1);
        if (v) k = t - 1ull - k;
    }
    return 0;
}
