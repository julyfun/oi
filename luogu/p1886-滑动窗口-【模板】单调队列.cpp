#include <iostream>
#include <queue>
using namespace std;
const int N = 1e6 + 10;
int n, k, a[N], ans[N];
deque<int> q, qmin; // q 里面存的是下标
void inq(int x) {
    while (!q.empty() && a[q.back()] <= a[x])
        q.pop_back(); // a[x] 又新又好，顶替前面的
    q.push_back(x);
    while (!qmin.empty() && a[qmin.back()] >= a[x])
        qmin.pop_back(); // a[x] 又新又好，顶替前面的
    qmin.push_back(x);
}
void outq(int x) {
    while (!q.empty() && q.front() <= x) // 超出窗口范围
        q.pop_front();
    while (!qmin.empty() && qmin.front() <= x)
        qmin.pop_front();
}
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= k - 1; i++) {
        inq(i);
    } // 准备第一个窗口
    // 接下来每一步滑动产生一个窗口.
    for (int i = k; i <= n; i++) {
        outq(i - k);
        inq(i);
        cout << a[qmin.front()] << ' '; // 最优解是队首
        ans[i] = a[q.front()];
    }
    cout << endl;
    for (int i = k; i <= n; i++)
        cout << ans[i] << ' ';
    return 0;
}
