#include <bits/stdc++.h>
using namespace std;
int R, C, T;
int arr[51][51];
int air;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
int sum;
void air_spread() {
    queue<pair<int, pair<int, int> > > q;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (arr[i][j] == -1) continue;
            if (arr[i][j] != 0) {
                q.push(make_pair(arr[i][j] / 5, make_pair(i, j)));
            }
        }
    }
    while (!q.empty()) {
        int air_5 = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        int cnt = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= R || ny >= C || arr[nx][ny] == -1) continue;
            arr[nx][ny] += air_5;
            cnt++;
        }
        arr[x][y] -= (air_5 * cnt);
    }
}

void air_purifier() {
    int x = air - 1, y = 0;
    int dir_x[4] = {0, -1, 0, 1};
    int dir_y[4] = {1, 0, -1, 0};
    int swap_num=0;
    int i=0;
    while (true) {
        int nx = x + dir_x[i];
        int ny = y + dir_y[i];
        if (nx < 0 || nx > air - 1 || ny < 0 || ny >= C){
            i++;
            continue;
        }
        if (arr[nx][ny] == -1) break;
        swap(arr[nx][ny], swap_num);
        x = nx;
        y = ny;
    }
    x = air, y = 0;
    int dir_x1[4] = {0, 1, 0, -1};
    int dir_y1[4] = {1, 0, -1, 0};
    swap_num = 0;
    i = 0;
    while (true) {
        int nx = x + dir_x1[i];
        int ny = y + dir_y1[i];
        if (nx < air || nx >= R || ny < 0 || ny >= C) {
            i++;
            continue;
        }
        if (arr[nx][ny] == -1) break;
        swap(arr[nx][ny], swap_num);
        x = nx;
        y = ny;
    }
    arr[air][0] = -1;
    arr[air -1][0] = -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> R >> C >> T;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == -1) {
                air = i;  // i와 i+1이 공기청정기 행
            }
        }
    }
    while (T--) {
        air_spread();
        air_purifier();
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (arr[i][j] != -1) {
                sum += arr[i][j];
            }
        }
    }
    cout << sum;
}