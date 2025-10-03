#include <bits/stdc++.h>
using namespace std;
int N, M, x, y, K;
int board[20][20];
int dice1[4] = {0, 0, 0, 0};
int dice2[4] = {0, 0, 0, 0};

int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};
void sync_row_from_col() {
    dice1[0] = dice2[0];
    dice1[2] = dice2[2];
}
void sync_col_from_row() {
    dice2[0] = dice1[0];
    dice2[2] = dice1[2];
}

void roll_east() {
    int t = dice1[0], e = dice1[1], b = dice1[2], w = dice1[3];
    dice1[0] = w;
    dice1[1] = t;
    dice1[2] = e;
    dice1[3] = b;
    sync_col_from_row();
}

void roll_west() {
    int t = dice1[0], e = dice1[1], b = dice1[2], w = dice1[3];
    dice1[0] = e;
    dice1[1] = b;
    dice1[2] = w;
    dice1[3] = t;
    sync_col_from_row();
}

void roll_north() {
    int t = dice2[0], n = dice2[1], b = dice2[2], s = dice2[3];
    dice2[0] = n;
    dice2[1] = b;
    dice2[2] = s;
    dice2[3] = t;
    sync_row_from_col();
}
void roll_south() {
    int t = dice2[0], n = dice2[1], b = dice2[2], s = dice2[3];
    dice2[0] = s;
    dice2[1] = t;
    dice2[2] = n;
    dice2[3] = b;
    sync_row_from_col();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> x >> y >> K;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) cin >> board[i][j];

    while (K--) {
        int dir;
        cin >> dir;
        int nx = x + dx[dir], ny = y + dy[dir];
        if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
            continue;
        }

        if (dir == 1)
            roll_east();
        else if (dir == 2)
            roll_west();
        else if (dir == 3)
            roll_north();
        else if (dir == 4)
            roll_south();
        x = nx;
        y = ny;

        if (board[x][y] == 0) {
            board[x][y] = dice1[2];  
            dice2[2] = dice1[2];     
        } else {
            dice1[2] = board[x][y];
            dice2[2] = board[x][y];
            board[x][y] = 0;
        }
        cout << dice1[0] << "\n";
    }
    return 0;
}
