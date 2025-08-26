#include <iostream>
#include <string>
using namespace std;
const int N = 1e5 + 10;
int x[N];
const int T = 2e5;
int f(string s) {
    if (s == "U") return 0;
    return s == "T" ? T : -T;
}
bool ins[N], vis[N]; int neg[N];
bool isnode(int x) {
    return x && abs(x) != T;
}
int find(int u, int d) {
    ins[u] = 1;
    vis[u] = 1;
    neg[u] = d;
    int v = abs(x[u]);
    if (!isnode(v)) {
        ins[u] = 0;
        return v;
    }
    if (vis[v]) {
        if (ins[v] && (d + (x[u] < 0) - neg[v]) & 1) {
            ins[u] = 0;
            return x[u] = 0;
        }
        ins[u] = 0;
        return x[u] = x[v];
    }
    x[u] = find(v, d + (x[u] < 0));
    ins[u] = 0;
    return x[u];
}
int main() {
    int c, t;
    cin >> c >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) { x[i] = i; neg[i] = 0; ins[i] = 0; vis[i] = 0; };
        for (int i = 1; i <= m; i++) {
            string s; cin >> s;
            int u, v; cin >> u;
            if (s == "+")  {
                cin >> v; x[u] = x[v];
                continue;
            }
            if (s == "-") {
                cin >> v; x[u] = -x[v];
                continue;
            }
            x[u] = f(s);
        }
        for (int i = 1; i <= n; i++)
            if (!vis[i])
                find(i, 0);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            // cout << i << ":" << x[i] << endl;
            if (x[i] == 0) 
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}

