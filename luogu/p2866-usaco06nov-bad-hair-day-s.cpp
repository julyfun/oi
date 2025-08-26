#include <iostream>
#include <stack>
using namespace std;
const int N = 8e4 + 10;
int h[N];
struct V {
    int num, h;
};
stack<V> st;
int main() {
    int n; cin >> n;
    long long ans = 0;
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = n; i >= 1; i--) {
        int num = 1;
        while (!st.empty() && h[i] > st.top().h) {
            ans += st.top().num;
            num += st.top().num;
            st.pop();
        }
        st.push({ num, h[i] });
    }
    cout << ans << endl;
    return 0;
}
