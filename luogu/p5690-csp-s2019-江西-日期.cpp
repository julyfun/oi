#include <iostream>
#include <string>
using namespace std;
const int d[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
string s, t;
int dif(string a, string b) {
    return int(a[0] != b[0]) + int(a[1] != b[1]);
}
string tos(int t) {
    if (t < 10) return "0" + to_string(t);
    return to_string(t);
}
int main() {
    cin >> s;
    t = s.substr(3, 2);
    s = s.substr(0, 2);
    int ans = 100;
    for (int i = 1; i <= 12; i++) {
        for (int j = 1; j <= d[i]; j++) {
            int r = dif(tos(i), s) + dif(tos(j), t);
            ans = min(ans, r);
        }
    }
    cout << ans << endl;
    return 0;
}
