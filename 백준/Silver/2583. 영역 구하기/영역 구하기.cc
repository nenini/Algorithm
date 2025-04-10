#include <bits/stdc++.h>
using namespace std;
int M, N, K;
int arr[100][100];
bool visited[100][100];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
int cnt;
int erea;
vector<int> vct;
void dfs(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
        if (arr[nx][ny] == 0 && !visited[nx][ny]) {
            erea++;
            dfs(nx, ny);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> M >> N >> K;
    for (int i = 0; i < K; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int k = y1; k < y2; k++) {
            for (int l = x1; l < x2; l++) {
                arr[k][l] = 1;
            }
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == 0 && !visited[i][j]) {
                erea = 1;
                dfs(i, j);
                vct.push_back(erea);
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
    sort(vct.begin(), vct.end());
    for (int i = 0; i < vct.size(); i++) {
        cout << vct[i] << " ";
    }
}