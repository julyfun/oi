// error1: 忘记清空 cnt
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int d[N], v[N], a[N];
struct Seg {
    // 每个超速车辆会被一段连续的测速仪检测出来.
    // x 表示首个能检测其超速的测速仪.
    // y 表示最后一个.
    int x, y;
} seg[N]; int cnt = 0;
int p[N];
bool cmp(Seg a, Seg b) {
    return a.y < b.y;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cnt = 0;
        int n, m, L, V;
        cin >> n >> m >> L >> V;
        for (int i = 1; i <= n; i++)
            cin >> d[i] >> v[i] >> a[i];
        for (int i = 1; i <= m; i++)
            cin >> p[i]; // 严格递增
        for (int i = 1; i <= n; i++) {
            // p 中首个 >= d[i]
            // 1 ~ m 合法.
            int low = lower_bound(p + 1, p + m + 1, d[i]) - p;
            if (a[i] == 0) {
                // 不加速:
                if (v[i] > V && low <= m) {
                    seg[++cnt] = { low, m };
                }
            } else if (a[i] > 0) {
                // 加速: 从 low ~ m 中找到第一个超速的检测仪.
                // res = -1 表示没找到
                int l = low, r = m, res = -1;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    // 需要 sqrt(v0^2 + 2*a*dis) >= V <=>
                    // v0^2 + 2 a dis >= V^2.
                    // 注意避免 sqrt 和除法，会有精度问题.
                    int dis = p[mid] - d[i];
                    if (v[i] * v[i] + 2 * a[i] * dis > V * V) {
                        res = mid;
                        r = mid - 1;
                    } else
                        l = mid + 1;
                }
                if (res != -1)
                    seg[++cnt] = { res, m };
            } else {
                // 减速: 找到最后一个超速的检测仪.
                int l = low, r = m, res = -1;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    int dis = p[mid] - d[i];
                    // 如果开不到, 那么左边 < 0
                    if (v[i] * v[i] + 2 * a[i] * dis > V * V) {
                        res = mid;
                        l = mid + 1;
                    } else
                        r = mid - 1;
                }
                if (res != -1)
                    seg[++cnt] = { low, res };
            }
        }
        int num = 0, r = -1;
        sort(seg + 1, seg + cnt + 1, cmp);
        for (int i = 1; i <= cnt; i++) {
            // 考察最早结束的线段.
            // 如果之前没有被覆盖，则必须开启一个检测仪.
            // 贪心开启最右端的是最优的.
            if (r < seg[i].x) {
                num++;
                r = seg[i].y;
            }
        }
        cout << cnt << " " << m - num << "\n";
    }
    return 0;
}
