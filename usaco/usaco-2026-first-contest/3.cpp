#include <iostream>
using namespace std;
typedef long long ll;
ll sc[510][510], cm = 0;
ll a[510][510];
int main() {
    int n, k;
    cin >> n >> k;
    int q;
    cin >> q;
    while (q--) {
        int r, c, v;
        cin >> r >> c >> v;
        for (int i = max(1, r - k + 1); i <= min(n - k + 1, r); i++)
            for (int j = max(1, c - k + 1); j <= min(n - k + 1, c); j++) {
                cm = max(cm, sc[i][j] += v - a[r][c]);
            }
        a[r][c] = v;
        cout << cm << "\n";
    }
    return 0;
}
