// 小 L 出正数还是负数呢？取决于小 Q 手里的数. 小 Q 的目标就是让你小.
// 如果小 Q 只有正数，你就应该出正数.
//  - 如果你有正数，就出最大的正数. => 小 Q 出最小的正数.
//  - 如果你没有正数，就出最大的负数. => 小 Q 出最大的正数.
// 如果小 Q 只有负数，你就应该出负数.
//  - 如果你有负数，就出最小的负数. => 小 Q 出最大的负数.
//  - 如果你没有负数，就出最小的正数. => 小 Q 出最大的负数.
// 如果小 Q 有正有负，你就从最大负数和最小正数中选择较优的. 又需要讨论.
// 下面的写法更简洁，枚举小 L 出正出负两种选择，根据小 Q 的反应计算结果，取最优解.
#include <bits/stdc++.h>
using namespace std; typedef long long ll;
int n, m, q; const int N = 1e5 + 10, T = 21;
const ll INF = 1e9 + 7;
ll a[N], b[N], lmin[N][T], lmax[N][T], rmin[N][T], rmax[N][T], lminpos[N][T], lmaxneg[N][T];
// 函数中传入数组，简化 ST 表预处理代码.
// 注意传入数组除了第一维以外的长度必须给定. 所以这里写 f[][T]
void calc(ll f[][T], int op) {
    for (int t = 1; t <= 20; t++)
        for (int i = 1; i + (1 << t) - 1 <= n; i++) {
            if (op == 0) f[i][t] = min(f[i][t - 1], f[i + (1 << (t - 1))][t - 1]);
            else f[i][t] = max(f[i][t - 1], f[i + (1 << (t - 1))][t - 1]);
        }
}
ll query(int l, int r, ll f[][T], int op) {
    int len = r - l + 1;
    int t = log2(len);
    if (op == 0) return min(f[l][t], f[r - (1 << t) + 1][t]);
    return max(f[l][t], f[r - (1 << t) + 1][t]);
}
int main() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        lmin[i][0] = lmax[i][0] = a[i];
        lmaxneg[i][0] = a[i] < 0 ? a[i] : -INF; // 表示无效
        lminpos[i][0] = a[i] >= 0 ? a[i] : +INF;
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i]; 
        rmin[i][0] = rmax[i][0] = b[i];
    }
    calc(lmin, 0); calc(rmin, 0); calc(lminpos, 0);
    calc(lmax, 1); calc(rmax, 1); calc(lmaxneg, 1);
    while (q--) {
        int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
        vector<ll> ans;
        ll lminn = query(l1, r1, lmin, 0);
        ll lmaxx = query(l1, r1, lmax, 1);
        ll rminn = query(l2, r2, rmin, 0);
        ll rmaxx = query(l2, r2, rmax, 1);
        ll lminposs = query(l1, r1, lminpos, 0);
        ll lmaxnegg = query(l1, r1, lmaxneg, 1);
        // 下面枚举小 L 的各种方案，选择最优解.
        if (lminn < 0) { // 小 L 方案一：出负数，前提是有负数.
            // 小 Q 若有正数，必选最大正数，
            // 所以小 L 应该出最大负数.
            if (rmaxx >= 0) ans.push_back(lmaxnegg * rmaxx);
            // 小 Q 若无正数，必选最大负数.
            // 所以小 L 应该出最小负数.
            else ans.push_back(lminn * rmaxx);
        }
        if (lmaxx >= 0) { // 小 L 方案二：出正数，前提是有正数.
            // 小 Q 若有负数，必选最小负数，
            // 所以小 L 应该出最小正数.
            if (rminn < 0) ans.push_back(lminposs * rminn);
            // 小 Q 若无负数，必选最小正数.
            // 所以小 L 应该出最大正数.
            else ans.push_back(lmaxx * rminn);
        }
        // 不确定 ans 有一个还是两个，干脆枚举取最大值输出.
        cout << (ans.size() == 1 ? ans[0] : max(ans[0], ans[1])) << endl;
    }
    return 0;
}
