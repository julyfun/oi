#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100;
int a[N];
int main2() {
    int n, m, c = 0;
    cin >> n >> m;
    if (n < m) swap(n, m);
    while (m) {
        a[++c] = n / m;
        int t = n % m;
        n = m;
        m = t;
    }
    reverse(a + 1, a + c + 1);
    int win = 0;
    for (int i = 1; i <= c; i++) {
        if (a[i] == 1)
            win = !win;
        else
            win = 1;
    }
    cout << (win ? "Stan wins\n" : "Ollie wins\n");
    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        main2();
    return 0;
}
