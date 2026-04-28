#include <iostream>
using namespace std;

int n, m;
int parent[1000001];

int find_parent(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find_parent(parent[x]);
}

void combine_set(int a, int b) {
    int ap = find_parent(a);
    int bp = find_parent(b);
    if (ap == bp) return;
    if (ap < bp)
        parent[bp] = ap;
    else
        parent[ap] = bp;
}

bool check_set(int a, int b) {
    int ap = find_parent(a);
    int bp = find_parent(b);
    if (ap == bp) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n + 1; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int oper, a, b;
        cin >> oper >> a >> b;
        if (oper == 0) {
            combine_set(a, b);
        } else {
            if (check_set(a, b)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}