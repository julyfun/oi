#include <iostream>
#include <stack>
using namespace std;
stack<int> s;
int main() {
    int n; cin >> n;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        while (!s.empty() && x >= s.top())
            s.pop();
        ans += s.size();
        s.push(x);
    }
    cout << ans << endl;
    return 0;
}
