#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
struct E { int v, w; };
struct Node {
    int u, d;
    bool operator<(const Node &t) const {
        return d > t.d;
    }
};
vector<E> e[N];
int n, m, dis[N], cnt[N];
priority_queue<Node> q;
int main() {
    cin >> n >> m;
    while (m--) {
        int u, v, w;
        cin >> v >> u >> w;
        e[u].push_back({v, w});
    }
    memset(dis, 0x3f, sizeof(dis));
    // 可能有多个连通块
    for (int i = 1; i <= n; i++) {
        if (cnt[i]) continue;
        dis[i] = 0;
        q.push({i, 0});
        cnt[i]++;
        while (!q.empty()) {
            auto [u, d] = q.top();
            q.pop();
            if (d > dis[u])
                continue;
            for (auto [v, w]: e[u]) {
                if (dis[u] + w < dis[v]) {
                    dis[v] = dis[u] + w;
                    q.push({v, dis[v]});
                    cnt[v]++;
                    if (cnt[v] > n) {
                        cout << "NO" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << dis[i] << ' ';
    return 0;
}
