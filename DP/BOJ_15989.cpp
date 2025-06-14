#include <bits/stdc++.h>
using namespace std;
int dp[10001][4];
int T;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    dp[1][1] = dp[1][2] = dp[1][3] = 1;
    dp[2][1]=1;
    dp[2][2] = 2;
    dp[2][3] = 2;
    dp[3][1] = 1;
    dp[3][2] = 2;
    dp[3][3] = 3;
    for (int i = 4; i <= 10000; i++) {
        dp[i][1] = dp[i - 1][1];
        dp[i][2] = dp[i][1] + dp[i - 2][2];
        dp[i][3] = dp[i][2] + dp[i - 3][3];
    }
    while (T--) {
        int n;
        cin >> n;
        cout << dp[n][3] << "\n";
    }
}