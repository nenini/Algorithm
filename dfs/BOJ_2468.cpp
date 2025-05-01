#include <bits/stdc++.h>
using namespace std;
int N;
int arr[100][100];
int cnt;
int height;
int result;
bool visited[100][100];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
void reset(){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
        }
    }
    cnt = 0;
}
void bfs(int x, int y, int k) { 
    queue<pair<int, int> > q;
    visited[x][y] = true;
    q.push(make_pair(x, y));
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (arr[nx][ny] > k && !visited[nx][ny]) {
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
            }
        }
    }
}
void dfs(int x, int y, int k) {
    visited[x][y] = true;
    for (int i = 0; i < 4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<0||ny<0||nx>=N||ny>=N) continue;
        if (arr[nx][ny] > k && !visited[nx][ny]) {
            dfs(nx, ny, k);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (height < arr[i][j]) {
                height = arr[i][j];
            }
        }
    }
    for (int k = 0; k < height; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (arr[i][j] >k && !visited[i][j]) {
                    bfs(i, j, k);
                    cnt++;
                }
            }
        }
        result = max(cnt, result);
        reset();
    }
    cout << result;
}