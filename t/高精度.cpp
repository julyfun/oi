#include <iostream>
#include <string>
using namespace std;
const int M = 10000;
const int V = 10086;
struct Bigint {
    int a[V];
    int p;
    Bigint(int n) {
        p = 0;
        while (n) {
            a[p] = n % M;
            n /= M;
            p++;
        }
    }
    Bigint operator+(const Bigint& y) {}
    string to_string() {
        if (p == 0)
            return "0";
        string s;
        for (int i = p - 1; i >= 0; i--)
            s += std::to_string(a[i]);
        return s;
    }
};

int main() {
    // tests
    Bigint n = 123124888;
    cout << n.to_string() << endl;
    return 0;
}
