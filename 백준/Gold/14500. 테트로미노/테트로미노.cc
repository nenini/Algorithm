#include <bits/stdc++.h>
using namespace std;
int N, M;
bool visited[500][500];
int arr[500][500];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
int result = 0;
void dfs(int depth, int sum, int x, int y) {
    if (depth == 3) {
        result = max(result, sum);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        if (visited[nx][ny]) continue;
        visited[nx][ny] = true;
        dfs(depth + 1, sum + arr[nx][ny], nx, ny);
        visited[nx][ny] = false;
    }
}
void three(int x, int y) {
    int sum;
    if (x - 1 >= 0 && y - 1 >= 0 && y + 1 < M) {
        sum = arr[x][y] + arr[x - 1][y] + arr[x][y - 1] + arr[x][y + 1];
        result = max(result, sum);
    }
    if (y - 1 >= 0 && y + 1 < M && x + 1 < N) {
        sum = arr[x][y] + arr[x + 1][y] + arr[x][y - 1] + arr[x][y + 1];
        result = max(result, sum);
    }
    if (x - 1 >= 0 && y + 1 < M && x + 1 < N) {
        sum = arr[x][y] + arr[x + 1][y] + arr[x - 1][y] + arr[x][y + 1];
        result = max(result, sum);
    }
    if (x - 1 >= 0 && y - 1 >=0 && x + 1 < N) {
        sum = arr[x][y] + arr[x + 1][y] + arr[x - 1][y] + arr[x][y - 1];
        result = max(result, sum);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = true;
            dfs(0, arr[i][j], i, j);
            visited[i][j] = false;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            three(i, j);
        }
    }
    cout << result;
}