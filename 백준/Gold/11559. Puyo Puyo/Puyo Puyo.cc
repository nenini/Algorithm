#include <bits/stdc++.h>
using namespace std;
char arr[12][6];
int visited[12][6];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
int result;
bool check;
void bfs(int x, int y) {
    vector<pair<int, int> > vct;
    queue<pair<int, int> > q;
    int num = 1;

    visited[x][y] = 1;
    q.push(make_pair(x, y));
    vct.push_back(make_pair(x, y));
    while (!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6) continue;
            if (!visited[nx][ny] && arr[xx][yy] == arr[nx][ny]) {
                visited[nx][ny] = 1;
                num++;
                q.push(make_pair(nx, ny));
                vct.push_back(make_pair(nx, ny));
            }
        }
    }
    if (num >= 4) {
        for (int i = 0; i < vct.size(); i++) {
            arr[vct[i].first][vct[i].second] = '.';
        }
        check = true;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }
    }
    while (true) {
        check = false;
        // 1연쇄
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 6; j++) {
                if (arr[i][j] != '.' && visited[i][j] != 1) {
                    bfs(i, j);
                    fill(&visited[0][0], &visited[11][6], 0);
                }
            }
        }  // 4개 이상 이어진 뿌요 전부 .으로 바꿈
        // 중력 작용
        if (!check) {
            // bfs에서 더이상 4개 이상 뿌요 발견 xx
            break;
        }
        for (int i =11; i >=0; i--) {
            for (int j = 6; j >=0; j--) {
                if (arr[i][j] != '.') {
                    int minu = i;
                    while (true) {
                        if (arr[minu + 1][j] == '.' && minu +1 >= 0) {
                            swap(arr[minu + 1][j], arr[minu][j]);
                            minu++;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        result++;
    }
    cout << result << "\n";
}