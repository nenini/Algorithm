#include <bits/stdc++.h>
using namespace std;
char arr[21][21];
bool visited[27];
int R, C;
int result;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
void dfs(int x, int y, int cnt) {
    result = max(result, cnt);
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
        if(!visited[arr[nx][ny]-'A']){
            visited[arr[nx][ny] - 'A'] = true;
            dfs(nx, ny, cnt + 1);
            visited[arr[nx][ny] - 'A'] = false;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
        }
    }
    visited[arr[0][0] - 'A'] = true;
    dfs(0, 0, 1);
    cout << result;
}