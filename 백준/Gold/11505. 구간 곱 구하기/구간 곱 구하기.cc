#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
long long arr[1000000];
long long tree[4000001];

long long tree_init(int node, int start, int end) {
    if (start >= end) return tree[node] = arr[start] % 1000000007;
    int middle = (start + end) / 2;
    return tree[node] = (tree_init(node * 2, start, middle) * tree_init(node * 2 + 1, middle + 1, end)) % 1000000007;
}

long long tree_multi(int node, int start, int end, int left, int right) {
    if (right < start || end < left) return 1;
    if (left <= start && right >= end) return tree[node];
    int middle = (start + end) / 2;
    return (tree_multi(node * 2, start, middle, left, right) * tree_multi(node * 2 + 1, middle + 1, end, left, right)) % 1000000007;
}

void tree_change(int node, int start, int end, int index, long long multi) {
    if (index < start || index > end) return;
    if (start == end) {
        tree[node] = multi % 1000000007;
        return;
    }
    if (start != end) {
        int middle = (start + end) / 2;
        tree_change(node * 2, start, middle, index, multi);
        tree_change(node * 2 + 1, middle + 1, end, index, multi);
        tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % 1000000007;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    tree_init(1,0,N-1);
    for (int i = 0; i < M + K; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            // change
            tree_change(1, 0, N - 1, b-1, c);
        } else if (a == 2) {
            // 곱셈
            cout << tree_multi(1, 0, N - 1, b-1, c-1)<< "\n";
        }
    }
}