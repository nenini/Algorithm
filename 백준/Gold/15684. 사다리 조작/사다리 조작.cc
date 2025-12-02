#include <bits/stdc++.h>
using namespace std;
int N, M, H;
bool arr[31][11];
int dx[4] = {1, 0, 0};
int dy[4] = {0, -1, 1};  // 하, 좌, 우
int result = INT_MAX;
// 사다리 확인 함수
bool check() {
    for (int i = 1; i <= N; i++) {
        int index = i;
        int horiz = 1;
        while (true) {
            if (index - 1 >= 1 && arr[horiz][index - 1]) {
                // 왼쪽으로 이동
                index -= 1;
                horiz += 1;
            } else if (index + 1 <= N && arr[horiz][index]) {
                // 오른쪽으로 이동
                index += 1;
                horiz += 1;
            } else {
                // 아래로 이동
                horiz += 1;
            }
            if (horiz >= H+1) break;
        }
        if (index != i) {
            return false;
        }
    }
    return true;
}

bool valid(int i, int j) {
    if (j - 1 >= 1 && arr[i][j - 1]) return false;
    if (j + 1 <= N && arr[i][j + 1]) return false;
    return true;
}
void dfs(int dept,int x, int y) {
    if(result<=dept){
        return;
    }
    if (dept == 4) {
        return;
    }
    if (check()) {
        result = min(result, dept);
        return;
    }
    for (int i = x; i <= H; i++) {
        int jstart;
        if(i==x){
            jstart=y;
        }else{
            jstart=1;
        }
        for (int j = jstart; j <= N - 1; j++) {
            if (!arr[i][j] && valid(i, j)) {
                arr[i][j] = true;
                dfs(dept + 1,i,j);
                arr[i][j] = false;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M >> H;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = true;
    }
    dfs(0,1,1);
    if (result == INT_MAX)
        cout << -1;
    else
        cout << result;
}