#include <bits/stdc++.h>

using namespace std;

int T;
int H, W, N;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int x, y;
char dir[4] = {'^', 'v', '<', '>'};
char arr[20][20];

void go(int num) {
    int nx = x + dx[num];
    int ny = y + dy[num];
    if (nx < 0 || ny < 0 || nx >= H || ny >= W) {
        arr[x][y] = dir[num];
        return;
    }
    if (arr[nx][ny] == '.') {
        arr[x][y] = '.';
        arr[nx][ny] = dir[num];
        x = nx;
        y = ny;
    } else {
        arr[x][y] = dir[num];
    }
}

void shoot() {
    int num;
    for (int i = 0; i < 4; i++) {
        if (dir[i] == arr[x][y]) {
            num = i;
            break;
        }
    }
    int nx = x;
    int ny = y;
    while (true) {
        nx += dx[num];
        ny += dy[num];
        if (nx < 0 || ny < 0 || nx >= H || ny >= W) {
            return;
        }
        if (arr[nx][ny] == '*') {
            arr[nx][ny] = '.';
            return;
        }
        if (arr[nx][ny] == '#') {
            return;
        }
    }
}
int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;

    for (int test = 1; test <= T; test++) {
        cin >> H >> W;
        for (int i = 0; i < H; i++) {
            string str;
            cin >> str;
            for (int j = 0; j < W; j++) {
                arr[i][j] = str[j];
                if (str[j] == '<' || str[j] == '>' || str[j] == '^' || str[j] == 'v') {
                    x = i;
                    y = j;
                }
            }
        }
        cin >> N;
        string input;
        cin >> input;
        for (int i = 0; i < N; i++) {
            if (input[i] == 'U') {
                go(0);
            } else if (input[i] == 'D') {
                go(1);
            } else if (input[i] == 'L') {
                go(2);
            } else if (input[i] == 'R') {
                go(3);
            } else {
                shoot();
            }
        }
        cout << "#" << test << " ";
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cout << arr[i][j];
            }
            cout << "\n";
        }
    }

    return 0;  // 정상종료시 반드시 0을 리턴해야합니다.
}