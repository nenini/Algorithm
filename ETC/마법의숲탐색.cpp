#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#define MAX_SIZE 71
using namespace std;

// 1. 골렘의 이동
// 1-1. 남쪽으로 내려감
// 1-2. 남쪽이 막혀있으면, 서쪽으로 회전하면서 내려감
// 1-3. 서쪽이 막혀있으면, 동쩍으로 회전하면서 내려감
// if) 골렘이 가장 남쪽 이동-> 몸 일부가 벗어남-> 숲 위치 골렘 전부 빠져나간 뒤, 탐색 다시 시작

// 2. 정령의 이동(상하좌우)
// 2-1. 만약 현재 위치하고 있는 골렘의 출구가 다른 골렘과 인접-> 이동
// 2-2. 가장 남쪽 칸으로 이동

// 출력: 정령의 최종 행 번호 합

int R, C, K;  // R,C: 숲의 크기, K: 정령의 수
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int arr[MAX_SIZE][MAX_SIZE];

bool emptyCell(int r, int c) {
    // 좌우 벽, 남쪽 벽은 막힘
    if (c < 1 || c > C || r > R) return false;

    // 북쪽 바깥은 들어오는 중에는 허용
    if (r < 1) return true;

    // 숲 내부면 빈칸인지 확인
    return arr[r][c] == 0;
}

bool is_south(int r, int c) { return emptyCell(r + 1, c - 1) && emptyCell(r + 2, c) && emptyCell(r + 1, c + 1); }

bool is_west(int r, int c) { return emptyCell(r - 1, c - 1) && emptyCell(r, c - 2) && emptyCell(r + 1, c - 1) && emptyCell(r + 1, c - 2) && emptyCell(r + 2, c - 1); }

bool is_east(int r, int c) { return emptyCell(r - 1, c + 1) && emptyCell(r, c + 2) && emptyCell(r + 1, c + 1) && emptyCell(r + 1, c + 2) && emptyCell(r + 2, c + 1); }

pair<int, int> move_golem(int i, int c, int d) {
    int r = -1;
    while (true) {
        // 남쪽
        if (is_south(r, c)) {
            r++;
        }
        // 안되면 서쪽
        else if (is_west(r, c)) {
            r++;
            c--;
            d = (d + 3) % 4;
        }
        // 안되면 동쪽
        else if (is_east(r, c)) {
            r++;
            c++;
            d = (d + 1) % 4;
        }
        // 골렘 이동 멈춤
        else {
            // 범위를 벗어남
            if (r <= 1) {
                memset(arr, 0, sizeof(arr));
                return {-1, -1};
            }

            arr[r][c] = i;
            for (int j = 0; j < 4; j++) {
                int nr = r + dx[j];
                int nc = c + dy[j];
                arr[nr][nc] = i;
            }
            arr[r + dx[d]][c + dy[d]] = -i;
            break;
        }
    }
    return {r, c};
}

int move_elemental(int i, int r, int c) {
    bool visited[R + 1][C + 1];
    memset(visited, false, sizeof(visited));

    queue<pair<int, int>> q;
    visited[r][c] = true;
    q.push({r, c});
    int max_row = r;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        max_row = max(max_row, cx);

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 1 || ny < 1 || nx > R || ny > C) continue;
            if (visited[nx][ny]) continue;
            if (arr[nx][ny] == 0) continue;

            int cur_golem = abs(arr[cx][cy]);
            int next_golem = abs(arr[nx][ny]);

            if (cur_golem == next_golem) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            } else {
                if (arr[cx][cy] < 0) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
    return max_row;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> R >> C >> K;
    int result = 0;
    for (int i = 1; i <= K; i++) {
        int c, d;
        cin >> c >> d;
        pair<int, int> pos = move_golem(i, c, d);
        if (pos.first == -1) continue;
        result += move_elemental(i, pos.first, pos.second);
    }
    cout << result;
    return 0;
}