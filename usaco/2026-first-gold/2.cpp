#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2e5 + 100;
int n, a[N];
struct node { int val, pos; };
vector<node> b;
ll ans;

bool cmp(node x, node y) {
    if (x.val != y.val) return x.val < y.val;
    return x.pos < y.pos;
}

struct BIT {
    ll f[N];
    void add(int x, int v) {
        for (; x <= n; x += x & -x) f[x] += v;
    }
    ll query(int x) {
        ll res = 0;
        for (; x; x -= x & -x) res += f[x];
        return res;
    }
    ll range(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
    void clear() {
        for (int i = 1; i <= n; i++) f[i] = 0;
    }
} T;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b.push_back({a[i], i});
    }
    sort(b.begin(), b.end(), cmp);
    
    for (int L = 0, R; L < n; L = R + 1) {
        R = L;
        while (R + 1 < n && b[R + 1].val == b[L].val) R++;
        for (int i = L; i <= R; i++) {
            // 左边和右边已处理（值更小）的元素个数，取小者作为该位置贡献
            ans += min(T.range(1, b[i].pos - 1), T.range(b[i].pos + 1, n));
        }
        for (int i = L; i <= R; i++) T.add(b[i].pos, 1); // 标记当前值已处理
    }
    cout << ans << '\n';
}

void clear() {
    b.clear(); ans = 0; T.clear();
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) solve(), clear();
    return 0;
}
