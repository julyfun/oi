#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) {
        int a; cin >> a;
        int k = a & (-a);
        cout << k << ' ' << 2 * k << ' ' << a + 2 * k << '\n';
    }
    return 0;
}

