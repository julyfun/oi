#include <iostream>
using namespace std;
const int N = 1e6 + 10;
const int M = 2e3 + 30;
int a[N], num[M], cnt;
int main() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int i = 1, j = 1;
    num[a[i]] = 1, cnt = 1;
    int x, y, ans = 1e9;
    while (j < n) {
        while (cnt < m && j < n) {
            j++;
            num[a[j]]++;
            if (num[a[j]] == 1) cnt++;
        }
        while (cnt == m) {
            if (j - i < ans) {
                ans = j - i;
                x = i, y = j;
            }
            num[a[i]]--;
            if (num[a[i]] == 0) cnt--;
            i++;
        }
    }
    cout << x << ' ' << y << endl;
    return 0;
}

