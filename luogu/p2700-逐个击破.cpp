#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef long long ll;
int a[N];
int col[N];
struct E {
    int u, v, w;
} e[N];
int fa[N];
int find(int x) {
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        // 输入 1, 2, 4
        int id;
        cin >> id;
        // 那么 col[1] = 1, col[2] = 2, col[4] = 3
        // col[id] 表示 id 这个点所拥有的敌人
        col[id] = i;
    }
    for (int i = 0; i <= n - 1; i++)
        fa[i] = i;
    ll sum = 0;
    for (int i = 1; i <= n - 1; i++)
        cin >> e[i].u >> e[i].v >> e[i].w;
    sort(e + 1, e + n, [](E a, E b) { return a.w > b.w; });
    for (int i = 1; i <= n - 1; i++) {
        auto [u, v, w] = e[i];
        int cu = col[find(u)];
        int cv = col[find(v)];
        if (cu && cv && cu != cv) {
            sum += w;
            continue;
        };
        // 由于是一个树，所以 u, v 一定是不同联通块的
        if (cu) fa[find(v)] = find(u);
        else fa[find(u)] = find(v);
    }
    cout << sum << "\n";
    return 0;
}

