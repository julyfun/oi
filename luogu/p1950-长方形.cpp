#include <iostream>
#include <stack>
using namespace std;
const int N = 1010;
char a[N][N];
int last[N];
struct Re {
    long long h, w;
};
int main() {
    // 维护单调增矩形序列
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i] + 1;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        stack<Re> s;
        long long sum = 0;
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == '*')
                last[j] = i;
            int h = i - last[j], w = 1;
            while (!s.empty() && s.top().h >= h) {
                w += s.top().w;
                sum -= s.top().w * s.top().h;
                s.pop();
            }
            s.push({ h, w });
            sum += h * w;
            ans += sum;
        }
    }
    cout << ans << endl;
    return 0;
}
