#include <bits/stdc++.h>
using namespace std;

enum { U = 0, D = 1, F = 2, B = 3, L = 4, R = 5 };

int T;
char cube[6][3][3];

void init_cube() {
    char color[6] = {'w', 'y', 'r', 'o', 'g', 'b'};
    for (int f = 0; f < 6; f++) {
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                cube[f][r][c] = color[f];
            }
        }
    }
}

void print_up() {
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            cout << cube[U][r][c];
        }
        cout << '\n';
    }
}

void rotate_face(int face, char dir) {
    char copy[6][3][3];
    for (int f = 0; f < 6; f++)
        for (int r = 0; r < 3; r++)
            for (int c = 0; c < 3; c++) copy[f][r][c] = cube[f][r][c];

    if (dir == '+') {  // 시계
        for (int r = 0; r < 3; r++)
            for (int c = 0; c < 3; c++) cube[face][c][2 - r] = copy[face][r][c];
    } else {  // 반시계
        for (int r = 0; r < 3; r++)
            for (int c = 0; c < 3; c++) cube[face][2 - c][r] = copy[face][r][c];
    }

    switch (face) {
        case U:
            if (dir == '+') {
                cube[F][0][0] = copy[R][0][0];
                cube[F][0][1] = copy[R][0][1];
                cube[F][0][2] = copy[R][0][2];

                cube[B][0][2] = copy[L][0][2];
                cube[B][0][1] = copy[L][0][1];
                cube[B][0][0] = copy[L][0][0];

                cube[L][0][0] = copy[F][0][0];
                cube[L][0][1] = copy[F][0][1];
                cube[L][0][2] = copy[F][0][2];

                cube[R][0][2] = copy[B][0][2];
                cube[R][0][1] = copy[B][0][1];
                cube[R][0][0] = copy[B][0][0];
            } else {
                // 반시계: 반대 방향 순환
                cube[F][0][0] = copy[L][0][0];
                cube[F][0][1] = copy[L][0][1];
                cube[F][0][2] = copy[L][0][2];

                cube[B][0][2] = copy[R][0][2];
                cube[B][0][1] = copy[R][0][1];
                cube[B][0][0] = copy[R][0][0];

                cube[L][0][0] = copy[B][0][0];
                cube[L][0][1] = copy[B][0][1];
                cube[L][0][2] = copy[B][0][2];

                cube[R][0][2] = copy[F][0][2];
                cube[R][0][1] = copy[F][0][1];
                cube[R][0][0] = copy[F][0][0];
            }
            break;

        case D:
            if (dir == '+') {
                cube[F][2][0] = copy[L][2][0];
                cube[F][2][1] = copy[L][2][1];
                cube[F][2][2] = copy[L][2][2];

                cube[B][2][2] = copy[R][2][2];
                cube[B][2][1] = copy[R][2][1];
                cube[B][2][0] = copy[R][2][0];

                cube[L][2][2] = copy[B][2][2];
                cube[L][2][1] = copy[B][2][1];
                cube[L][2][0] = copy[B][2][0];

                cube[R][2][0] = copy[F][2][0];
                cube[R][2][1] = copy[F][2][1];
                cube[R][2][2] = copy[F][2][2];
            } else {
                cube[F][2][0] = copy[R][2][0];
                cube[F][2][1] = copy[R][2][1];
                cube[F][2][2] = copy[R][2][2];

                cube[B][2][2] = copy[L][2][2];
                cube[B][2][1] = copy[L][2][1];
                cube[B][2][0] = copy[L][2][0];

                cube[L][2][2] = copy[F][2][2];
                cube[L][2][1] = copy[F][2][1];
                cube[L][2][0] = copy[F][2][0];

                cube[R][2][0] = copy[B][2][0];
                cube[R][2][1] = copy[B][2][1];
                cube[R][2][2] = copy[B][2][2];
            }
            break;

        case F:
            if (dir == '+') {
                cube[U][2][0] = copy[L][2][2];
                cube[U][2][1] = copy[L][1][2];
                cube[U][2][2] = copy[L][0][2];

                cube[D][0][0] = copy[R][2][0];
                cube[D][0][1] = copy[R][1][0];
                cube[D][0][2] = copy[R][0][0];

                cube[L][0][2] = copy[D][0][0];
                cube[L][1][2] = copy[D][0][1];
                cube[L][2][2] = copy[D][0][2];

                cube[R][0][0] = copy[U][2][0];
                cube[R][1][0] = copy[U][2][1];
                cube[R][2][0] = copy[U][2][2];
            } else {
                cube[U][2][0] = copy[R][0][0];
                cube[U][2][1] = copy[R][1][0];
                cube[U][2][2] = copy[R][2][0];

                cube[D][0][0] = copy[L][0][2];
                cube[D][0][1] = copy[L][1][2];
                cube[D][0][2] = copy[L][2][2];

                cube[L][0][2] = copy[U][2][2];
                cube[L][1][2] = copy[U][2][1];
                cube[L][2][2] = copy[U][2][0];

                cube[R][0][0] = copy[D][0][2];
                cube[R][1][0] = copy[D][0][1];
                cube[R][2][0] = copy[D][0][0];
            }
            break;

        case B:
            if (dir == '+') {
                cube[U][0][2] = copy[R][2][2];
                cube[U][0][1] = copy[R][1][2];
                cube[U][0][0] = copy[R][0][2];

                cube[D][2][2] = copy[L][2][0];
                cube[D][2][1] = copy[L][1][0];
                cube[D][2][0] = copy[L][0][0];

                cube[L][0][0] = copy[U][0][2];
                cube[L][1][0] = copy[U][0][1];
                cube[L][2][0] = copy[U][0][0];

                cube[R][0][2] = copy[D][2][2];
                cube[R][1][2] = copy[D][2][1];
                cube[R][2][2] = copy[D][2][0];
            } else {
                cube[U][0][2] = copy[L][0][0];
                cube[U][0][1] = copy[L][1][0];
                cube[U][0][0] = copy[L][2][0];

                cube[D][2][2] = copy[R][0][2];
                cube[D][2][1] = copy[R][1][2];
                cube[D][2][0] = copy[R][2][2];

                cube[L][0][0] = copy[D][2][0];
                cube[L][1][0] = copy[D][2][1];
                cube[L][2][0] = copy[D][2][2];

                cube[R][0][2] = copy[U][0][0];
                cube[R][1][2] = copy[U][0][1];
                cube[R][2][2] = copy[U][0][2];
            }
            break;

        case L:
            if (dir == '+') {
                cube[U][0][0] = copy[B][2][2];
                cube[U][1][0] = copy[B][1][2];
                cube[U][2][0] = copy[B][0][2];

                cube[D][2][0] = copy[F][2][0];
                cube[D][1][0] = copy[F][1][0];
                cube[D][0][0] = copy[F][0][0];

                cube[F][0][0] = copy[U][0][0];
                cube[F][1][0] = copy[U][1][0];
                cube[F][2][0] = copy[U][2][0];

                cube[B][0][2] = copy[D][2][0];
                cube[B][1][2] = copy[D][1][0];
                cube[B][2][2] = copy[D][0][0];
            } else {
                cube[U][0][0] = copy[F][0][0];
                cube[U][1][0] = copy[F][1][0];
                cube[U][2][0] = copy[F][2][0];

                cube[D][2][0] = copy[B][0][2];
                cube[D][1][0] = copy[B][1][2];
                cube[D][0][0] = copy[B][2][2];

                cube[F][0][0] = copy[D][0][0];
                cube[F][1][0] = copy[D][1][0];
                cube[F][2][0] = copy[D][2][0];

                cube[B][0][2] = copy[U][2][0];
                cube[B][1][2] = copy[U][1][0];
                cube[B][2][2] = copy[U][0][0];
            }
            break;

        case R:
            if (dir == '+') {
                cube[U][2][2] = copy[F][2][2];
                cube[U][1][2] = copy[F][1][2];
                cube[U][0][2] = copy[F][0][2];

                cube[D][0][2] = copy[B][2][0];
                cube[D][1][2] = copy[B][1][0];
                cube[D][2][2] = copy[B][0][0];

                cube[F][0][2] = copy[D][0][2];
                cube[F][1][2] = copy[D][1][2];
                cube[F][2][2] = copy[D][2][2];

                cube[B][0][0] = copy[U][2][2];
                cube[B][1][0] = copy[U][1][2];
                cube[B][2][0] = copy[U][0][2];
            } else {
                cube[U][2][2] = copy[B][0][0];
                cube[U][1][2] = copy[B][1][0];
                cube[U][0][2] = copy[B][2][0];

                cube[D][0][2] = copy[F][0][2];
                cube[D][1][2] = copy[F][1][2];
                cube[D][2][2] = copy[F][2][2];

                cube[F][0][2] = copy[U][0][2];
                cube[F][1][2] = copy[U][1][2];
                cube[F][2][2] = copy[U][2][2];

                cube[B][0][0] = copy[D][2][2];
                cube[B][1][0] = copy[D][1][2];
                cube[B][2][0] = copy[D][0][2];
            }
            break;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        init_cube();

        while (n--) {
            string cmd;
            cin >> cmd;
            char f = cmd[0];
            char d = cmd[1];

            int faceIdx;
            if (f == 'U')
                faceIdx = U;
            else if (f == 'D')
                faceIdx = D;
            else if (f == 'F')
                faceIdx = F;
            else if (f == 'B')
                faceIdx = B;
            else if (f == 'L')
                faceIdx = L;
            else
                faceIdx = R;

            rotate_face(faceIdx, d);
        }
        print_up();
    }
    return 0;
}
