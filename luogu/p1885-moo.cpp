#include <bits/stdc++.h>
using namespace std;
char s(int i, int n, int len) {
    int mid = i + 3;
    int pre = (len - mid) / 2;
    if (n == pre + 1)
        return 'm';
    if (n > pre && n <= pre + mid)
        return 'o';
    if (n > pre + mid)
        return s(i - 1, n - pre - mid, pre);
    return s(i - 1, n, pre);
}
int main() {
    int n;
    cin >> n;
    int i = 0, len = 3;
    while (len < n) {
        i += 1;
        len = len * 2 + i + 3;
    }
    cout << s(i, n, len);
    return 0;
}
