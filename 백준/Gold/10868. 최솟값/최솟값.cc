#include <bits/stdc++.h>
using namespace std;
long long arr[100000];
long long tree[400001];
int N, M;

long long tree_init(int node, int start, int end) {
    if (start == end) return tree[node] = arr[start];

    int middle = (start + end) / 2;

    return tree[node] = min(tree_init(node * 2, start, middle) ,tree_init(node * 2 + 1, middle + 1, end));
}

long long tree_min(int node,int start, int end, int left, int right){
    if (end < left || start > right) return LLONG_MAX;

    if(left<=start&&right>=end) return tree[node];
    int middle=(start+end)/2;

    return min(tree_min(node * 2, start, middle, left, right) , tree_min(node * 2 + 1, middle + 1, end, left, right));
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // 트리 초기화
    tree_init(1, 0, N - 1);

    for (int i = 0; i < M; i++) {
        long long a, b;
        cin >> a >> b;
        long long min_num = tree_min(1, 0, N - 1, a-1, b - 1);
        cout << min_num << "\n";
    }
}