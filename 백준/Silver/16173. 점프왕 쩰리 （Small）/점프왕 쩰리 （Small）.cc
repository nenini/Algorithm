#include <bits/stdc++.h>
using namespace std;
int N;
int arr[3][3];
bool result;
void dfs(int x, int y) {
    if (x < 0 || y < 0 || x >= N || y >= N || result) return;
    if (arr[x][y] == 0) return;
    if (arr[x][y] == -1) {
        result = true;
        return;
    }
    dfs(x + arr[x][y], y);
    dfs(x, y + arr[x][y]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin>>arr[i][j];
        }
    }
    dfs(0, 0);
    if (result) {
        cout << "HaruHaru";
    } else {
        cout << "Hing";
    }
}