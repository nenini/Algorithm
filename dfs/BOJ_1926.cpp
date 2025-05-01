#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[500][500];
int cnt;
int num;
int result;
bool visited[500][500];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
void dfs(int x, int y) {
    num++;
    visited[x][y] = true;
    for (int i = 0; i < 4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<0||ny<0||nx>=n||ny>=m) continue;
        if(arr[nx][ny]==1&&!visited[nx][ny]){
            dfs(nx, ny);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1 && !visited[i][j]) {
                dfs(i, j);
                cnt++;
                result = max(result, num);
                num = 0;
            }
        }
    }
    cout << cnt << "\n";
    cout << result;
}