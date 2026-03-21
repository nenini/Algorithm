#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define SIZE 41
#define MAX_KNIGHT 31

using namespace std;

// 빈칸(0), 함정(1), 벽(2)
// 기사 초기 위치 (r,c) 을 좌측 상단으로 하는 h x w
// 기사 체력 k

// 1) 기사 이동
// 1-1) 상하좌우 이동(0:상/ 1: 우/ 2:하/ 3:좌)
// 1-2) 만약 이동하려는 위치에 다른 기사 있다면 -> 함께 연쇄적으로 밀림
// 1-3) 만약 이동하려는 방향의 끝에 벽이 있다면 -> 모든 기사 이동 x
// 1-4) 체스판에서 사라진 기사에게 명령 x

// 2) 대결 대미지
// 2-1) 다른 기사 밀침, 각 기사들은 해당 기사가 이동한 곳에서 w x h 직사각형 내 놓여있는 함정 수만큼 피해(함정이 없으면 대미지 X)
// 2-2) 만약 현재 체력 이상의 대미지-> 기사 사라짐
// 2-3) 명령을 받은 기사는 대미지 x

// 출력: 생존한 기사들이 총 받는 대미지 합

int L, N, Q;  // L: 체스판 크기/ N: 기사 수/ Q: 명령어 수

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

struct Knight {
    int r;
    int c;
    int h;
    int w;
    int k;  // 체력이 0보다 작으면
    int damage;
};

int chess[SIZE][SIZE];
Knight knight[MAX_KNIGHT];

void battle(vector<int> moved, int d) {
    for (int i = 0; i < moved.size(); i++) {
        int idx = moved[i];
        int nr = knight[idx].r + dx[d];
        int nc = knight[idx].c + dy[d];

        int sum = 0;
        for (int r = nr; r < nr + knight[idx].h; r++) {
            for (int c = nc; c < nc + knight[idx].w; c++) {
                if (chess[r][c] == 1) sum++;
            }
        }
        knight[idx].r = nr;
        knight[idx].c = nc;
        if (i != 0) {
            knight[idx].k -= sum;
            knight[idx].damage += sum;
        }
    }
}

bool is_wall(vector<int> moved, int d) {
    for (int i = 0; i < moved.size(); i++) {
        int idx = moved[i];
        int nr = knight[idx].r + dx[d];
        int nc = knight[idx].c + dy[d];

        for (int r = nr; r < nr + knight[idx].h; r++) {
            for (int c = nc; c < nc + knight[idx].w; c++) {
                if (r < 1 || c < 1 || r > L || c > L) return true;
                if (chess[r][c] == 2) return true;
            }
        }
    }
    return false;
}

bool is_overlap(int idx1, int idx2, int d) {
    Knight k1 = knight[idx1];
    Knight k2 = knight[idx2];
    if (k1.r + dx[d] + k1.h - 1 < k2.r) return false;
    if (k2.r + k2.h - 1 < k1.r + dx[d]) return false;
    if (k1.c + dy[d] + k1.w - 1 < k2.c) return false;
    if (k2.c + k2.w - 1 < k1.c + dy[d]) return false;
    return true;
}

void move(int i, int d) {
    if (knight[i].k <= 0) return;
    bool visited[MAX_KNIGHT];
    memset(visited, false, sizeof(visited));
    queue<int> q;
    vector<int> moved;

    q.push(i);
    visited[i] = true;

    while (!q.empty()) {
        int c = q.front();
        q.pop();
        moved.push_back(c);
        for (int n = 1; n <= N; n++) {
            if (n == c || knight[n].k <= 0 || visited[n]) continue;

            if (is_overlap(c, n, d)) {
                q.push(n);
                visited[n] = true;
            }
        }
    }

    if (!is_wall(moved, d)) {
        battle(moved, d);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> L >> N >> Q;
    for (int i = 1; i <= L; i++) {
        for (int j = 1; j <= L; j++) {
            cin >> chess[i][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        int r, c, h, w, k;
        cin >> r >> c >> h >> w >> k;
        knight[i] = {r, c, h, w, k, 0};
    }
    for (int op = 0; op < Q; op++) {
        int i, d;
        cin >> i >> d;
        // i번 기사에게 d로 한칸 이동하라
        move(i, d);
    }
    int result = 0;
    for (int i = 1; i <= N; i++) {
        if (knight[i].k > 0) {
            result += knight[i].damage;
        }
    }
    cout << result;
    return 0;
}