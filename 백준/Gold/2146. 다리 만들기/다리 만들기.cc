#include <bits/stdc++.h>
using namespace std;

int N;
int arr[100][100];
int dist[100][100];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
bool visited[100][100];
int result = INT_MAX;
int bfs(int x, int y) {
    memset(dist, -1, sizeof(dist));

    int start = arr[x][y];
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    dist[x][y] = 0;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        
        if (dist[cx][cy] >= result) continue;
        for (int k = 0; k < 4; k++) {
            int nx = cx + dx[k];
            int ny = cy + dy[k];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

            if (arr[nx][ny] == 0 && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[cx][cy] + 1;
                q.push({nx, ny});
            }
            else if (arr[nx][ny] > 0 && arr[nx][ny] != start) {
                return dist[cx][cy];
            }
        }
    }
    return INT_MAX;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    int num = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j] && arr[i][j] == 1) {
                num++;
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                visited[i][j] = true;
                arr[i][j] = num;

                while (!q.empty()) {
                    int cx = q.front().first;
                    int cy = q.front().second;
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = cx + dx[k];
                        int ny = cy + dy[k];
                        if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                        if (!visited[nx][ny]) {
                            if (arr[nx][ny] == 1) {
                                q.push(make_pair(nx, ny));
                                visited[nx][ny] = true;
                                arr[nx][ny] = num;
                            } 
                        }
                    }
                }
            }
        }
    }

    

        for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] > 0) {
                int num = bfs(i, j);
                result = min(num, result);
            }
        }
    }
    cout << result;
}