#include <bits/stdc++.h>
#define N_MAX 51
#define LR_MAX 101
using namespace std;
int N, L, R;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
int arr[N_MAX][N_MAX];
int result;
bool visited[N_MAX][N_MAX];
bool check;

void bfs(int x, int y) {
    int sum = arr[x][y];
    int count = 1;
    visited[x][y] = true;
    queue<pair<int, int>> q;
    vector<pair<int, int>> vct;  // 평균 내야하는 연합 도시
    vct.push_back(make_pair(x, y));
    q.push(make_pair(x, y));

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

            int diff = abs(arr[cx][cy] - arr[nx][ny]);
            if (!visited[nx][ny] && diff >= L && diff <= R) {
                q.push(make_pair(nx, ny));
                vct.push_back(make_pair(nx, ny));
                visited[nx][ny] = true;
                sum += arr[nx][ny];
                count++;
                check = true;
            }
        }
    }
    int person_count = sum / count;

    for (int i = 0; i < vct.size(); i++) {
        arr[vct[i].first][vct[i].second] = person_count;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    while (true) {
        check = false;
        fill(visited[0], visited[N+1], false);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j]) {
                    bfs(i, j);
                }
            }
        }
        if (!check) {
            cout << result;
            return 0;
        }
        result++;
    }
}