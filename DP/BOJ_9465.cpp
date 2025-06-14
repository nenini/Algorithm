#include <bits/stdc++.h>
using namespace std;
int T, n;
int arr[2][100001];
int dp[2][100001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n;
        for (int j = 0; j < 2; j++) {
            for (int k = 1; k <= n;k++){
                cin >> arr[j][k];
            }
        }
        dp[0][1] = arr[0][1];
        dp[1][1] = arr[1][1];
        for (int k = 2; k <= n; k++) {
            dp[0][k] = max(dp[1][k - 1], dp[1][k - 2])+arr[0][k];
            dp[1][k] = max(dp[0][k - 1], dp[0][k - 2])+arr[1][k];
        }
        cout << max(dp[0][n], dp[1][n])<<"\n";
    }
}