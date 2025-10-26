#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1e9;
const int V = 10086;
struct Big {
    ll a[V] = { 0 }; // 9 digits
    int p;
    Big(ll n) {
        p = 0;
        while (n) {
            a[p] = n % M;
            n /= M;
            p++;
        }
    }
    string to_string() {
        if (p == 0)
            return "0";
        string s;
        if (a[p - 1] < 0) s += "-";
        for (int i = p - 1; i >= 0; i--) {
            string t = std::to_string(abs(a[i]));
            if (i != p - 1) {
                int q = 9 - t.length();
                assert(q >= 0);
                while (q--) s += "0";
            }
            s += t;
        }
        return s;
    }
    // up to 1 digit
    void up(int i) {
        a[i + 1] += a[i] / M;
        a[i] %= M;
    }
    void down(int i) {
        p = i;
        while (p && a[p - 1] == 0) p--;
    }
    static Big from_string(const string& s) {
        Big res = 0;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            int j = len - 1 - i;
            res.a[j / 9] = res.a[j / 9] * 10 + s[i] - '0';
        }
        res.p = (len - 1) / 9 + 1;
        return res;
    }
    Big operator-() const {
        Big res = *this;
        for (int i = 0; i < p; i++)
            res.a[i] = -res.a[i];
        return res;
    }
};

Big operator+(const Big& x, const Big& y) {
    Big res = 0;
    int q = max(x.p, y.p);
    for (int i = 0; i < q; i++) {
        res.a[i] += x.a[i] + y.a[i];
        res.up(i);
    }
    res.down(q + 1);
    return res;
}
// fft next time.
Big operator*(const Big& x, const Big& y) {
    Big res = 0;
    for (int i = 0; i < x.p; i++) {
        for (int j = 0; j < y.p; j++) {
            res.a[i + j] += x.a[i] * y.a[j];
            res.up(i + j);
        }
        res.up(i + y.p);
    }
    res.down(x.p + y.p);
    return res;
}
Big operator-(const Big& x, const Big& y) {
    return x + (-y);
}
Big operator/(const Big& x, const Big& y) {

}
int main() {
    string s, t; cin >> s >> t;
    cout << (Big::from_string(s) * Big::from_string(t)).to_string() << endl;
    return 0;
}

