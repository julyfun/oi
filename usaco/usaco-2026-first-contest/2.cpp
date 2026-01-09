#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int c[300010];
int main() {
    int t, k; cin >> t >> k;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        n *= 3;
        if (n % 2 == 1) {
            cout << -1 << "\n";
            continue;
        }
        bool ok = true;
        for (int i = 0; i < n / 2; i++)
            if (s[i] != s[i + n / 2]) {
                ok = false;
                break;
            }
        if (ok) {
            cout << 1 << "\n";
            for (int i = 0; i < n; i++)
                cout << 1 << " \n"[i == n - 1];
            continue;
        }
        cout << 2 << "\n";
        memset(c, 0, n * sizeof(int));
        // COW OWC WCO
        // 13: CO
        // 12: OW
        // 23: WC
        for (int i = 0; i < n / 2; i += 3) {
            string l = s.substr(i, 3);
            string r = s.substr(i + s.size() / 2, 3);
            // 寻找 CO, OW, WC 哪个同时出现在左右两小段中.
            for (string sub: {"CO", "OW", "WC"}) {
                if (l.find(sub) != string::npos && r.find(sub) != string::npos) {
                    for (int j = 0; j < 3; j++) {
                        c[i + j] = (sub.find(l[j]) == string::npos) + 1;
                        c[i + j + n / 2] = (sub.find(r[j]) == string::npos) + 1;
                    }
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++)
            cout << c[i] << " \n"[i == n - 1];
    }
    return 0;
}