#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2010, M = N * N + N;
int fa[N];
struct E {
	int x, y;
	ll z;
} e[M];
bool cmp(const E& a, const E& b) {
	return a.z < b.z;
}
int find(int x) {
	if (x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
int x[N], y[N]; ll k[N];
ll dis(int i, int j) {
    return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}
int build[N], be[N];
int main() {
	int n, m = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> x[i] >> y[i];
	for (int i = 1; i <= n; i++) {
		int w; cin >> w;
		e[++m] = E { 0, i, w };
	}
    for (int i = 1; i <= n; i++)
        cin >> k[i];
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            e[++m] = { i, j, dis(i, j) * (k[i] + k[j]) };
	sort(e + 1, e + m + 1, cmp);
	for (int i = 0; i <= n; i++)
		fa[i] = i;
	ll sum = 0, cnt = 0, bcnt = 0, ecnt = 0;
	for (int i = 1; i <= m; i++) {
		int x = e[i].x, y = e[i].y;
        if (x > y) swap(x, y);
		if (find(x) != find(y)) {
			fa[find(x)] = find(y);
			sum += e[i].z;
            cnt++;
            if (x == 0)
                build[++bcnt] = y;
            else
                be[++ecnt] = i;
		}
	}
	cout << sum << "\n";
    cout << bcnt << "\n";
    for (int i = 1; i <= bcnt; i++)
        cout << build[i] << " ";
    cout << "\n";
    cout << ecnt << "\n";
    for (int i = 1; i <= ecnt; i++)
        cout << e[be[i]].x << " " << e[be[i]].y << "\n";
	return 0;
}
