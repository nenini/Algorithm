#include <bits/stdc++.h>
using namespace std;
vector<int> selected;
int N;
int arr[14];
void dfs(int idx) {
    if (selected.size() == 6) {
        for (int i = 0; i < 6; i++) {
            cout << selected[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = idx; i < N; i++) {
        selected.push_back(arr[i]);
        dfs(i + 1);
        selected.pop_back();
    }
}
int main() {
    while (true) {
        cin >> N;
        if (N == 0) return 0;
        for (int i = 0; i < N; i++) {
            cin>>arr[i];
        }
        dfs(0);
        cout << "\n";
    }
}