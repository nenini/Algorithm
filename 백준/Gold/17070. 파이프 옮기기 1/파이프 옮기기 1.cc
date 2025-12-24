#include <bits/stdc++.h>
using namespace std;
int dp[17][17][3];
int arr[17][17];
int N;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }
    dp[1][2][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (arr[i][j] == 1) continue;
            // 가로
            if (j + 1 <= N && arr[i][j + 1] != 1) {
                dp[i][j + 1][0] += dp[i][j][0];
            }
            if (i + 1 <= N && j + 1 <= N && arr[i + 1][j + 1] != 1 && arr[i + 1][j] != 1 && arr[i][j + 1] != 1) {
                dp[i + 1][j + 1][2] += dp[i][j][0];
            }

            // 세로
            if (i + 1 <= N && arr[i + 1][j] != 1) {
                dp[i + 1][j][1] += dp[i][j][1];
            }
            if (i + 1 <= N && j + 1 <= N && arr[i + 1][j + 1] != 1 && arr[i + 1][j] != 1 && arr[i][j + 1] != 1) {
                dp[i + 1][j + 1][2] += dp[i][j][1];
            }

            // 대각선
            if (j + 1 <= N && arr[i][j + 1] != 1) {
                dp[i][j + 1][0] += dp[i][j][2];
            }
            if (i + 1 <= N && arr[i + 1][j] != 1) {
                dp[i + 1][j][1] += dp[i][j][2];
            }
            if (i + 1 <= N && j + 1 <= N && arr[i + 1][j + 1] != 1 && arr[i + 1][j] != 1 && arr[i][j + 1] != 1) {
                dp[i + 1][j + 1][2] += dp[i][j][2];
            }
        }
    }
    cout << dp[N][N][0] + dp[N][N][1] + dp[N][N][2];
}