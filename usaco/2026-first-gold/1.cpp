#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;

int n, m, a[N], p[N], sz[N], h[N], cur[N], old[N], cnt[3], ans[N][3];
struct Q { int c, t; } q[N];

int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }

void uni(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) {
        p[x] = y; sz[y] += sz[x];
        if (h[y] != -1) cnt[h[y]] += sz[x]; // 合并时若根有颜色，把x块加到该颜色计数
    }
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> m;
    memset(cur, -1, sizeof cur);
    for (int i = 1; i <= m; i++) {
        char c; cin >> q[i].c >> c;
        q[i].t = c == 'C' ? 0 : c == 'O' ? 1 : 2;
        old[i] = cur[q[i].c];
        cur[q[i].c] = q[i].t;
    }
    for (int i = 1; i <= n; i++) p[i] = i, sz[i] = 1, h[i] = cur[i];
    for (int i = 1; i <= n; i++) if (cur[i] == -1) uni(i, a[i]); // 初始无类型者与其朋友合并
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= n; i++) if (p[i] == i && h[i] != -1) cnt[h[i]] += sz[i];
    for (int i = m; i >= 1; i--) {
        ans[i][0] = cnt[0]; ans[i][1] = cnt[1]; ans[i][2] = cnt[2];
        int u = q[i].c, rt = find(u);
        cnt[cur[u]] -= sz[rt]; // 撤销当前类型贡献
        cur[u] = old[i];       // 回退到上一状态
        if (cur[u] != -1) {
            h[rt] = cur[u];
            cnt[cur[u]] += sz[rt]; // 新类型生效
        } else {
            h[rt] = -1;
            uni(u, a[u]); // 无类型则重新与朋友合并
        }
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << "\n";
}
