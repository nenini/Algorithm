#include <bits/stdc++.h>
using namespace std;

int fish_num[4][4];
int fish_direct[4][4];
int dx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dy[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};

int result = 0;

void fish_move(int shark_x, int shark_y, int shark_direct, int sum) {
    int numCopy[4][4];
    int dirCopy[4][4];
    memcpy(numCopy, fish_num, sizeof(fish_num));
    memcpy(dirCopy, fish_direct, sizeof(fish_direct));
    // 물고기 이동
    for (int num = 1; num <= 16; num++) {
        bool check = false;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (fish_num[i][j] == num) {
                    for (int d = 0; d <= 7; d++) {
                        int dir = (fish_direct[i][j] + d - 1) % 8 + 1;
                        int nx = i + dx[dir];
                        int ny = j + dy[dir];
                        if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) continue;
                        if (nx == shark_x && ny == shark_y) continue;
                        // 빈칸 혹은 다른 물고기가 있는 칸-> 위치 바꿈
                        fish_num[i][j] = fish_num[nx][ny];
                        fish_direct[i][j] = fish_direct[nx][ny];
                        fish_num[nx][ny] = num;
                        fish_direct[nx][ny] = dir;
                        check = true;
                        break;
                    }
                }
                if (check) break;
            }
            if (check) break;
        }
    }
    int sharkCopy[4][4];
    int dir_sharkCopy[4][4];
    memcpy(sharkCopy, fish_num, sizeof(fish_num));
    memcpy(dir_sharkCopy, fish_direct, sizeof(fish_direct));

    // 상어 이동
    int nshark_x = shark_x, nshark_y = shark_y;
    while (true) {
        nshark_x += dx[shark_direct];
        nshark_y += dy[shark_direct];
        if (nshark_x < 0 || nshark_y < 0 || nshark_x >= 4 || nshark_y >= 4) {
            break;
        }
        if (fish_num[nshark_x][nshark_y] == 0) continue;

        int eaten = fish_num[nshark_x][nshark_y];
        result = max(result, sum + fish_num[nshark_x][nshark_y]);
        fish_num[nshark_x][nshark_y] = 0;
        fish_move(nshark_x, nshark_y, fish_direct[nshark_x][nshark_y], sum + eaten);
        memcpy(fish_num, sharkCopy, sizeof(fish_num));
        memcpy(fish_direct, dir_sharkCopy, sizeof(fish_direct));
    }

    memcpy(fish_num, numCopy, sizeof(fish_num));
    memcpy(fish_direct, dirCopy, sizeof(fish_direct));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int a, b;
            cin >> a >> b;
            fish_num[i][j] = a;
            fish_direct[i][j] = b;
        }
    }

    result += fish_num[0][0];
    fish_num[0][0] = 0;
    
    fish_move(0, 0, fish_direct[0][0], result);
    cout << result;
}
