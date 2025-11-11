// 22:16

#include <bits/stdc++.h>
using namespace std;

int R, C;
int startx, starty;
char arr[1001][1001];
bool visited[1001][1001];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
queue<pair<int, int> > fire_position;
void fire() {
    int size = fire_position.size();
    for (int i = 0; i < size; i++) {
        int x = fire_position.front().first;
        int y = fire_position.front().second;
        fire_position.pop();
        for (int j = 0; j < 4; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (nx < 0 || ny < 0 || nx > R-1 || ny > C-1) continue;
            if (arr[nx][ny] == '#' || arr[nx][ny] == 'F') continue;
            arr[nx][ny] = 'F';
            fire_position.push(make_pair(nx, ny));
        }
    }
}

int bfs(int x, int y, int time) {
    fire();
    queue<pair<pair<int, int>, int> > q;
    q.push(make_pair(make_pair(x, y), time));
    visited[x][y] = true;
    int tt=time;
    while (!q.empty()) {
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int ct = q.front().second;
        q.pop();
        if(ct!=tt){
            fire();
            tt=ct;
        }
        if (cx == R - 1 || cy == C - 1 || cx == 0 || cy == 0) {
            // if(ct==1&&arr[cx][cy]=='F') return -1;
            return ct;
        }
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || ny < 0 || nx > R-1 || ny > C-1) continue;
            if (arr[nx][ny] == '#' || arr[nx][ny] == 'F') continue;
            if (!visited[nx][ny]) {
                visited[nx][ny]=true;
                q.push(make_pair(make_pair(nx, ny), ct + 1));
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < C; j++) {
            arr[i][j] = str[j];
            if (str[j] == 'J') {
                startx = i;
                starty = j;
            } else if (str[j] == 'F') {
                fire_position.push(make_pair(i, j));
            }
        }
    }
    int result = bfs(startx, starty, 1);
    if (result == -1) {
        cout << "IMPOSSIBLE";
    } else {
        cout << result;
    }
}