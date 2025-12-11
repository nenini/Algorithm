#include <bits/stdc++.h>
using namespace std;
int N;

long long arr[100000];
long long tree[400001];

long long tree_init(int node, int start, int end) {
    if (start == end) return tree[node] = start;
    int middle = (start + end) / 2;
    int left_index = tree_init(node * 2, start, middle);
    int right_index = tree_init(node * 2 + 1, middle + 1, end);
    if (arr[left_index] < arr[right_index])
        return tree[node] = left_index;
    else
        return tree[node] = right_index;
}

long long tree_min(int node, int start, int end, int left, int right) {
    if (end < left || start > right) return -1;
    if (left <= start && right >= end) return tree[node];

    int middle = (start + end) / 2;

    int left_index = tree_min(node * 2, start, middle, left, right);
    int right_index = tree_min(node * 2 + 1, middle + 1, end, left, right);
    if (left_index==-1) return right_index;
    if (right_index == -1) return left_index;

    if (arr[left_index] < arr[right_index])
        return left_index;
    else
        return right_index;
}

long long triangle_sum(int left, int right) {
    if (left > right) return 0;
    int curr_min = tree_min(1, 0, N - 1, left, right);
    long long curr_sum = (right - left + 1) * arr[curr_min];

    return max(curr_sum, max(triangle_sum(left, curr_min - 1), triangle_sum(curr_min + 1, right)));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    tree_init(1, 0, N - 1);
    cout << triangle_sum(0, N - 1);
}