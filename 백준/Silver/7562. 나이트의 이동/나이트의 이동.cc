#include <bits/stdc++.h>
using namespace std;
int N, I;
int x1, y_1, x2, y2;
int visited[300][300];
int dx[8] = {-1,-2,-1,-2,1,2,1,2};
int dy[8] = {-2,-1,2,1,2,1,-2,-1};
void bfs(int x, int y) {
    memset(visited, -1, sizeof(visited));
    queue<pair<int, int> > q;
    visited[x][y] = 0;
    if (x == x2 && y == y2) {
        cout << 0 << "\n";
        return;
    }
    q.push(make_pair(x, y));
    while(!q.empty()){
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();
        if (xx == x2 && yy == y2) {
            cout << visited[xx][yy]<<"\n";
            return;
        }
        for (int i = 0; i < 8;i++){
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            if(nx<0||ny<0||nx>=I||ny>=I) continue;
            if(visited[nx][ny]==-1){
                visited[nx][ny] = visited[xx][yy] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> I;
        cin >> x1 >> y_1 >> x2 >> y2;
        bfs(x1, y_1);
    }
}