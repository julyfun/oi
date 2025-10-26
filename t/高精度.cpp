#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1e9;
const int V = 20010;
struct Big {
    ll a[V] = { 0 }; // 9 digits
    int p = 0;
    Big() {}
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
        Big res;
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
    Big shift(int x) const {
        assert(x >= 0);
        Big res = 0;

    }
    ll at(int x) const {
        ll k = a[x / 9];
        x %= 9;
        while (x--)
            k /= 10;
        return k % 10;
    }
    static pair<Big, Big> div(const Big& x, const Big& y);
};
Big operator+(const Big& x, const Big& y) {
    Big res;
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
    Big res;
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
Big& operator-=(Big& x, const Big& y) {
    x = x - y;
    return x;
}
bool operator==(const Big& x, const Big& y) {
    if (x.p != y.p) return false;
    for (int i = 0; i < x.p; i++)
        if (x.a[i] != y.a[i])
            return false;
    return true;
}
bool operator<(const Big& x, const Big& y) {
    int q = max(x.p, y.p);
    for (int i = q; i >= 0; i--)
        if (x.a[i] != y.a[i])
            return x.a[i] < y.a[i];
    return false;
}
bool operator<=(const Big& x, const Big& y) {
    return x < y || x == y;
}
Big operator/(const Big& x, const Big& y) {
    return Big::div(x, y).first;
}
Big operator%(const Big& x, const Big& y) {
    return Big::div(x, y).second;
}
pair<Big, Big> Big::div(const Big& x, const Big& y) {
    Big res = 0;
    Big mod = x;
    int up = x.p + 1 - y.p;
    for (int i = up; i >= 0; i--) {
        // find biggest t in 9..0 that t * y <= mod
        ll l = 1, r = 9, ans = 0;
        while (l <= r) {
            ll mid = (l + r) / 2;
            if (Big(mid) * y <= mod) {
                ans = mid;
                l = mid + 1;
            } else
                r = mid - 1;
        }
        res.a[i] = ans;
        mod -= Big(ans) * y;
    }
    res.down(up);
    return { res, mod };
}
int main() {
    string s, t; cin >> s >> t;
    auto a = Big::from_string(s);
    auto b = Big::from_string(t);
    cout << (a + b).to_string() << "\n";
    cout << (a - b).to_string() << "\n";
    cout << (a * b).to_string() << "\n";
    cout << (a / b).to_string() << "\n";
    cout << (a % b).to_string() << "\n";
    return 0;
}

