#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int N = 1e5 + 10;
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
struct Num {
    ll p, q; // p / q
    Num operator+(Num b) {
        ll g = gcd(q, b.q);
        ll lcm = q / g * b.q;
        ll np = p * (lcm / q) + b.p * (lcm / b.q);
        ll nq = lcm;
        ll ng = gcd(np, nq);
        return {np / ng, nq / ng};
    }
    Num operator/(ll b) {
        ll g = gcd(p, b);
        return {p / g, q * (b / g)};
    }
};
vector<int> e[N]; int in[N];
Num f[N];
int main() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int d;
        cin >> d;
        while (d--) {
            int v; cin >> v;
            e[i].push_back(v);
            in[v]++;
        }
        f[i] = {0, 1};
    }
    for (int i = 1; i <= m; i++)
        f[i] = {1, 1};
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (in[i] == 0)
            q.push(i);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v: e[u]) {
            f[v] = f[v] + (f[u] / e[u].size());
            if (--in[v] == 0)
                q.push(v);
        }
    }
    for (int i = 1; i <= n; i++)
        if (e[i].size() == 0)
            cout << f[i].p << " " << f[i].q << "\n";
    return 0;
}
