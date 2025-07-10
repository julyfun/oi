#include <iostream>
#include <vector>
using namespace std;
const int N = 310;
struct E {
    int v, w;
};
vector<E> e[N];
int n, s;

int main() {
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }

}
