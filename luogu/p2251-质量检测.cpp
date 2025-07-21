#include <iostream>
#include <queue>
using namespace std;
const int N = 1e5 + 10;
deque<int> q;
int n, m, a[N];
void inq(int x) {
    while (!q.empty() && a[q.back()] >= a[x])
        q.pop_back();
    q.push_back(x);
}
void outq(int x) {
    while (!q.empty() && q.front() < x)
        q.pop_front();
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m - 1; i++)
        inq(i);
    for (int i = 1; i <= n - m + 1; i++) {
        outq(i);
        inq(i + m - 1);
        cout << a[q.front()] << endl;
    }
    return 0;
}
