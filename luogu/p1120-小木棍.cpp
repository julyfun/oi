#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int a[100];
bool used[100];
int n, sum = 0;
void dfs(int id, int res, int tar) {
    if (id == sum / tar + 1) {
        cout << tar << endl;
        exit(0);
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i] && res >= a[i] && !(res != tar && b[cnt - 1] == a[i])) {
            used[i] = true;
            if (res == a[i])
                dfs(id + 1, tar, tar);
            else
                dfs(id, res - a[i], tar);
            used[i] = false;
        }
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a + 1, a + n + 1, greater<int>());
    for (int i = 1; i <= sum; i++)
        if (sum % i == 0)
            dfs(1, i, i, 1);
    return 0;
}
