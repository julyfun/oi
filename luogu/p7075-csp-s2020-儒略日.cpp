#include <iostream>
#include <string>
using namespace std;

const int N15821015 = 0;
const int N15830101 = 0;
const int N16000101 = 0;
const int G1 = 365;
const int G4 = 4 * G1 + 1;
const int G100 = 25 * G4 - 1;
const int G400 = 4 * G100 + 1;
struct Date {
    int y, m, d, typ;
};
bool g_big(int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}
Date f16000101(int n) {
    int n400 = n / G400, m400 = n % G400;
    int n100 = m400 / G100, m100 = n % G100;
    int n4 = m100 / G4, m4 = n % G4;
}
void solve() {
    int n; cin >> n;
    if (n >= N15830101)
        cout << f15830101(n - N15830101) << endl;
}
int main() {
    int q;
    while (q--)
        solve();
    return 0;
}
