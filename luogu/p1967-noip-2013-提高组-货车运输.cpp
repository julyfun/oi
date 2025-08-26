#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10, M = 5e4 + 10;
int fa[N], ans[30010];
int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}
set<int> s[N];
struct E {
    int u, v, w;
} e[M];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= m; i++)
        cin >> e[i].u >> e[i].v >> e[i].w;
    sort(e + 1, e + m + 1, [](E a, E b) { return a.w > b.w; });
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        s[x].insert(i);
        s[y].insert(i);
    }
    memset(ans, -1, sizeof(ans));
    for (int i = 1; i <= m; i++) {
        int u = e[i].u, v = e[i].v;
        int ru = find(u), rv = find(v);
        if (ru != rv) {
            // <=: 如此一来，每个点最多转移 log 次
            // 转移复杂度 log, 总复杂度 nlogn logn
            // >=: 线段树式合并，即可搞到 n logn long 复杂度
            if (s[ru].size() > s[rv].size())
                swap(ru, rv);
            fa[ru] = find(rv);
            for (auto it = s[ru].begin(); it != s[ru].end(); it++) {
                if (s[rv].find(*it) != s[rv].end()) {
                    ans[*it] = e[i].w;
                    s[rv].erase(*it);
                    continue;
                }
                s[rv].insert(*it);
            }
            s[ru].clear();
        }
    }
    for (int i = 1; i <= q; i++)
        cout << ans[i] << '\n';
    return 0;
}

