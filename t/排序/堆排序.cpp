#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int a[500005];
int main() {
    int n;
    cin >> n;
    // 上升法
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int p = i;
        while (true) {
            int fa = p / 2; // p 的父亲
            if (p == 1 || a[fa] <= a[p])
                break;
            swap(a[fa], a[p]);
            p = fa;
        }
    }
    // 取出交换，下降法
    for (int i = 1; i <= n; i++) {
        int cnt = n + 1 - i;
        cout << a[1] << ' ';
        swap(a[1], a[cnt]);
        int p = 1;
        while (true) {
            int l = p * 2;
            int r = p * 2 + 1;
            if (l >= cnt && r >= cnt)
                break;
            if (r >= cnt) {
                if (a[l] >= a[p])
                    break;
                swap(a[l], a[p]);
                p = l;
                continue;
            }
            if (min(a[l], a[r]) >= a[p])
                break;
            if (a[l] < a[r]) {
                swap(a[l], a[p]);
                p = l;
            } else {
                swap(a[r], a[p]);
                p = r;
            }
        }
    }
    return 0;
}
