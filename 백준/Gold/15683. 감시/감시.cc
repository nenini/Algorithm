#include <bits/stdc++.h>
using namespace std;
int N, M;
int arr[8][8];
int dx[4] = {-1, 0, 1, 0};  // 상우하좌
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int>> vct;
int result = INT_MAX;
void dfs(int size) {

    if (size == vct.size()) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (arr[i][j] == 0) {
                    sum++;
                }
            }
        }
        result = min(result, sum);
        return;
    }

    int x = vct[size].first;
    int y = vct[size].second;
    int cctv = arr[x][y];
    if (cctv == 1) {
        for (int i = 0; i < 4; i++) {
            int temp[8][8];
            memcpy(temp, arr, sizeof(arr));
            int nx = x;
            int ny = y;
            while (true) {
                nx = nx + dx[i];
                ny = ny + dy[i];
                if (nx < 0 || ny < 0 || nx >= N || ny >= M || arr[nx][ny] == 6) break;
                if (arr[nx][ny] == 0) arr[nx][ny] = -1;
            }
            dfs(size + 1);
            memcpy(arr, temp, sizeof(temp));
        }
    } else if (cctv == 2) {
        for (int i = 0; i < 2; i++) {
            int temp[8][8];
            memcpy(temp, arr, sizeof(arr));
            for (int j = 0; j <= 2; j += 2) {
                int nx = x;
                int ny = y;
                while (true) {
                    nx = nx + dx[i + j];
                    ny = ny + dy[i + j];
                    if (nx < 0 || ny < 0 || nx >= N || ny >= M || arr[nx][ny] == 6) break;
                    if (arr[nx][ny] == 0) arr[nx][ny] = -1;
                }
            }
            dfs(size + 1);
            memcpy(arr, temp, sizeof(temp));
        }
    } else if (cctv == 3) {
        for (int i = 0; i < 4; i++) {
            int temp[8][8];
            memcpy(temp, arr, sizeof(arr));
            for (int j = 0; j <= 1; j++) {
                int nx = x;
                int ny = y;
                int num = i + j;
                if (num >= 4) num -= 4;
                while (true) {
                    nx = nx + dx[num];
                    ny = ny + dy[num];
                    if (nx < 0 || ny < 0 || nx >= N || ny >= M || arr[nx][ny] == 6) break;
                    if(arr[nx][ny]==0)arr[nx][ny] = -1;
                }
            }
            dfs(size + 1);
            memcpy(arr, temp, sizeof(temp));
        }
    } else if (cctv == 4) {
        for (int i = 0; i < 4; i++) {
            int temp[8][8];
            memcpy(temp, arr, sizeof(arr));

            for (int j = 0; j <= 2; j++) {
                int nx = x;
                int ny = y;
                int num = i + j;
                if (num >= 4) num -= 4;
                while (true) {
                    nx = nx + dx[num];
                    ny = ny + dy[num];
                    if (nx < 0 || ny < 0 || nx >= N || ny >= M || arr[nx][ny] == 6) break;
                    if (arr[nx][ny] == 0) arr[nx][ny] = -1;
                }
            }
            dfs(size + 1);
            memcpy(arr, temp, sizeof(temp));
        }
    } else {
        int temp[8][8];
        memcpy(temp, arr, sizeof(arr));

        for (int i = 0; i < 4; i++) {
            int nx = x;
            int ny = y;
            while (true) {
                nx = nx + dx[i];
                ny = ny + dy[i];
                if (nx < 0 || ny < 0 || nx >= N || ny >= M || arr[nx][ny] == 6) break;
                if (arr[nx][ny] == 0) arr[nx][ny] = -1;
            }
        }
        dfs(size + 1);
        memcpy(arr, temp, sizeof(temp));
    }
}
int main() {
    ios::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] >= 1 && arr[i][j] <= 5) {
                vct.push_back(make_pair(i, j));
            }
        }
    }
    dfs(0);
    cout << result;
}