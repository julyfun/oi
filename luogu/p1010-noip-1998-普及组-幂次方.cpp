#include <bits/stdc++.h>
using namespace std;
void solve(int n) {
    if (n == 1) {
        cout << "2(0)";
        return;
    }
    if (n == 2) {
        cout << 2;
        return;
    }
    int t = 1;
    while (1 << (t + 1) <= n) t++;
    if (t == 1)
        cout << 2;
    else {
        cout << "2(";
        solve(t);
        cout << ")";
    }
    if (n > 1 << t) {
        cout << "+";
        solve(n - (1 << t));
    }
}

int main() {
    int n;
    cin >> n;
    solve(n);
    return 0;
}
