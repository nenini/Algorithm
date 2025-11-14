#include <bits/stdc++.h>
using namespace std;
int N, M;
char arr[10][10];
pair<int, int> red;
pair<int, int> blue;
bool visited[10][10][10][10];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

int result = 1;
queue<pair<pair<int, int>, pair<int, int>>> q;

bool bfs() {
    int q_size = q.size();
    for (int i = 0; i < q_size; i++) {
        int curr_red_x = q.front().first.first;
        int curr_red_y = q.front().first.second;
        int curr_blue_x = q.front().second.first;
        int curr_blue_y = q.front().second.second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int next_red_x = curr_red_x;
            int next_red_y = curr_red_y;
            int next_blue_x = curr_blue_x;
            int next_blue_y = curr_blue_y;
            bool red_check = false, blue_check = false;
            int red_count = 0, blue_count = 0;
            while (true) {
                red_check = false, blue_check = false;
                if (arr[next_red_x + dx[i]][next_red_y + dy[i]] == '#') {
                    break;
                }
                next_red_x += dx[i];
                next_red_y += dy[i];
                red_count++;
                if (arr[next_red_x][next_red_y] == 'O') {
                    red_check = true;
                    break;
                }
            }
            while (true) {
                if (arr[next_blue_x + dx[i]][next_blue_y + dy[i]] == '#') {
                    break;
                }
                next_blue_x += dx[i];
                next_blue_y += dy[i];
                blue_count++;
                if (arr[next_blue_x][next_blue_y] == 'O') {
                    blue_check = true;
                    break;
                }
            }
            if (next_red_x == next_blue_x && next_red_y == next_blue_y){
                if(red_count<blue_count){
                    next_blue_x -= dx[i];
                    next_blue_y -= dy[i];
                } else {
                    next_red_x -= dx[i];
                    next_red_y -= dy[i];
                }
            }
                if (visited[next_red_x][next_red_y][next_blue_x][next_blue_y]) continue;
            if (red_check && !blue_check) {  // 빨간색이 구멍에 들어가고 파란색은 안들어감
                return true;
            } else if (!red_check && !blue_check) {  // 둘다 안들어감
                visited[next_red_x][next_red_y][next_blue_x][next_blue_y] = true;
                q.push(make_pair(make_pair(next_red_x, next_red_y), make_pair(next_blue_x, next_blue_y)));
            }
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < M; j++) {
            arr[i][j] = str[j];
            if (arr[i][j] == 'R') {
                red = make_pair(i, j);
            } else if (arr[i][j] == 'B') {
                blue = make_pair(i, j);
            }
        }
    }
    q.push(make_pair(make_pair(red.first, red.second), make_pair(blue.first, blue.second)));
    visited[red.first][red.second][blue.first][blue.second] = true;
    while (true) {
        if (!bfs()) {
            result++;
        } else {
            cout << result;
            return 0;
        }
        if (result > 10) {
            cout << -1;
            return 0;
        }
    }
}