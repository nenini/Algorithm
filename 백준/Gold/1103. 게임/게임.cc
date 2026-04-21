#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int N, M;
int dp[50][50];
bool visited[50][50];
char arr[50][50];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

bool move(int x, int y, int dir, int num) {
    int nx = x + num * dx[dir];
    int ny = y + num * dy[dir];
    if (nx < 0 || ny < 0 || nx >= N || ny >= M) return false;
    if (arr[nx][ny] == 'H') return false;
    return true;
}

bool dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int num = arr[x][y] - '0';
        if (move(x, y, i, num)) {
            int nx = x + num * dx[i];
            int ny = y + num * dy[i];
            if (visited[nx][ny]) {
                return true;
            }
            if (dp[nx][ny] != 0) {
                dp[x][y] = max(dp[x][y], dp[nx][ny] + 1);
                continue;
            } else {
                visited[nx][ny] = true;

                if (dfs(nx, ny)) {
                    return true;
                }
                dp[x][y] = max(dp[x][y], dp[nx][ny] + 1);
                visited[nx][ny] = false;
            }

        } else {
            dp[x][y] = max(dp[x][y], 1);
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < M; j++) {
            arr[i][j] = row[j];
        }
    }
    memset(dp, 0, sizeof(dp));
    visited[0][0]=true;
    dp[0][0]=1;
    if (dfs(0, 0))
        cout << -1;
    else
        cout << dp[0][0];
}