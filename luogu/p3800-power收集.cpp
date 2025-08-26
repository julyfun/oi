#include <bits/stdc++.h>
using namespace std;
const int N = 4e3 + 10;
int f[N];
struct V {
    int x, y, v;
} v[N];
bool cmp(const V& a, const V& b) {
    return a.x < b.x;
}
int main() {
    int n, m, k, t;
    cin >> n >> m >> k >> t;
    for (int i = 1; i <= k; i++)
        cin >> v[i].x >> v[i].y >> v[i].v;
    sort(v + 1, v + k + 1, cmp);
    int ans = 0;
    for (int i = 1; i <= k; i++) {
        f[i] = v[i].v;
        for (int j = 1; j < i; j++) {
            if ((v[i].x - v[j].x) * t >= abs(v[i].y - v[j].y))
                f[i] = max(f[i], f[j] + v[i].v);
        }
    }
    for (int i = 1; i <= k; i++)
        ans = max(ans, f[i]);
    cout << ans << endl;
    return 0;
}

