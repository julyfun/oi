#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;
int a[N];
string s, t;
int n;
bool ok(int x) {
    return x >= 1 && x <= 2 * n;
}
bool ok2(int x, int y) {
    return ok(x) && ok(y) && x < y && a[x] == a[y];
}
bool step(int l, int r, int x, int y) {
    // **l.....x****y....r**
    // 2 1 1 2
    //   l   r
    //     x   
    //     y
    // * 1 2 * 1 2
    // * l x   y r
    // * * lx* * yr
    //
    // 3 1 2 3 1 2
    // 3 1 2 2 3 1 ok
    if (l > x && y > r)
        return true;
    if (ok2(l, x)) {
        s += "L";
        t += "L";
        return step(l + 1, r, x - 1, y);
    }
    if (ok2(l, y)) {
        s += "L";
        t += "R";
        return step(l + 1, r, x, y + 1);
    }
    // 以下两个只有一个可能成立.
    if (ok2(x, r)) {
        s += "R";
        t += "L";
        return step(l, r - 1, x - 1, y);
    }
    if (ok2(y, r)) {
        s += "R";
        t += "R";
        return step(l, r - 1, x, y + 1);
    }
    return false;
}

int main() {
    int m; cin >> m;
    while (m--) {
        int lpos, rpos;
        cin >> n;
        for (int i = 1; i <= 2 * n; i++) {
            cin >> a[i];
            if (i > 1 && a[i] == a[1])
                lpos = i;
        }
        for (int i = 2 * n - 1; i >= 1; i--)
            if (a[i] == a[2 * n])
                rpos = i;
        // if (lpos == 2 * n) {
        s = "L";
        t = "L";
        if (step(2, 2 * n, lpos - 1, lpos + 1)) {
            reverse(t.begin() ,t.end());
            cout << s << t << endl;
            continue;
        }
        s = "R";
        t = "L";
        if (step(1, 2 * n - 1, rpos - 1, rpos + 1)) {
            reverse(t.begin(), t.end());
            cout << s << t << endl;
            continue;
        }
        cout << "-1" << endl;
        
    }
    return 0;
}
