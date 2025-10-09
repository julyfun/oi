#include <bits/stdc++.h>
using namespace std;
bool fate[1030][1030];
void div(int x1, int x2, int y1, int y2) {
    int mx = (x1 + x2) / 2, my = (y1 + y2) / 2;
    if (x2 - x1 == 1) {
        fate[x1 + 1][y1] = 1;
        fate[x1 + 1][y1 + 1] = 1;
        fate[x1][y1 + 1] = 1;
        return;
    }
    div(mx + 1, x2, y1, my);
    div(mx + 1, x2, my + 1, y2);
    div(x1, mx, my + 1, y2);
}
int main() {
    int n;
    cin >> n;
    div(1, 1 << n, 1, 1 << n);
    for (int i = 1; i <= 1 << n; i++) {
        for (int j = 1; j <= 1 << n; j++)
            cout << fate[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}
