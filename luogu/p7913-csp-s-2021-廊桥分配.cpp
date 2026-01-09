// 证明每架飞机最终停在哪个廊桥 与分配的廊桥个数无关:
// 考虑 1 个廊桥的情况，假设 p1, p2 .. px 分配到 1 号.
// 考虑 2 个廊桥的情况，不论 2 号廊桥分配给谁，
// 在 p2 落地时，1 号廊桥一定空闲, ... 依此类推
// 反证: p1~p2 之间 x 占领 1 号廊桥 =>
// x 与 p1 无交 => x 在 1 个廊桥时就会占领 1 号廊桥，矛盾
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int w1[N], w2[N];
struct S {
    int x, y;
} s[N];
struct E {
    int t, lev;
    bool operator<(E b) const {
        return t > b.t;
    }
};
void solve(int w[], int n) {
    set<int> st;
    priority_queue<E> q;
    for (int i = 1; i <= n; i++)
        st.insert(i);
    for (int i = 1; i <= n; i++) {
        while (!q.empty() && q.top().t <= s[i].x) {
            st.insert(q.top().lev);
            q.pop();
        }
        int lev = *(st.begin());
        w[lev]++;
        q.push({ s[i].y, lev });
        st.erase(lev);
    }
}

int main() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    for (int i = 1; i <= m1; i++)
        cin >> s[i].x >> s[i].y;
    sort(s + 1, s + m1 + 1, [](S x, S y) { return x.x < y.x; });
    solve(w1, m1);
    for (int i = 1; i <= n; i++)
        w1[i] += w1[i - 1];
    for (int i = 1; i <= m2; i++)
        cin >> s[i].x >> s[i].y;
    sort(s + 1, s + m2 + 1, [](S x, S y) { return x.x < y.x; });
    solve(w2, m2);
    for (int i = 1; i <= n; i++)
        w2[i] += w2[i - 1];
    int ans = 0;
    for (int i = 0; i <= n; i++)
        ans = max(ans, w1[i] + w2[n - i]);
    cout << ans << "\n";
    return 0;
}
