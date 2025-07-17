#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int N = 5e3 + 10;
struct E {
    int v, w;
};
vector<E> e[N];
int n, m;
int dis[N], cnt[N];
bool inq[N];
int main() {
    cin >> n >> m;
    while (m--) {
        int u, v, w;
        cin >> v >> u >> w;
        e[u].push_back({v, w});
    }
    memset(dis, 0x3f, sizeof(dis));
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (cnt[i]) continue;
        dis[i] = 0;
        q.push(i);
        inq[i] = 1;
        cnt[i]++;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            inq[u] = 0;
            for (auto [v, w]: e[u]) {
                if (dis[u] + w < dis[v]) {
                    dis[v] = dis[u] + w;
                    if (!inq[v]) {
                        q.push(v);
                        inq[v] = 1;
                        cnt[v]++;
                        if (cnt[v] > n) {
                            cout << "NO" << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << dis[i] << ' ';
    return 0;
}
