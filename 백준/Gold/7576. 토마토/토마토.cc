#include <bits/stdc++.h>
using namespace std;
int arr[1000][1000];
int M, N;
queue<pair<int, int> > q;
int min_num;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
void bfs() {
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0||ny<0||nx>=N||ny>=M) continue;
            if(arr[nx][ny]==0){
                q.push(make_pair(nx, ny));
                arr[nx][ny] = arr[x][y] + 1;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> M >> N;
    for (int i = 0; i < N;i++){
        for (int j = 0; j < M;j++){
            cin >> arr[i][j];
            if(arr[i][j]==1){
                q.push(make_pair(i, j));
            }
        }
    }
    bfs();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if(arr[i][j]==0){
                cout << -1;
                return 0;
            }
            min_num = max(arr[i][j], min_num);
        }
    }
    cout << min_num-1;
}