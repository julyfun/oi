#include <iostream>
using namespace std;
const int N = 3010;
int n, m;
char ma[N], mi[N];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        ma[i] = 0;
        mi[i] = 127;
        for (int j = 0; j < m; j++) {
            ma[i] = max(ma[i], s[j]);
            mi[i] = min(mi[i], s[j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        bool ok = true;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (mi[i] >= ma[j])
                ok = false;
        }
        cout << ok;
    }
    return 0;
}

