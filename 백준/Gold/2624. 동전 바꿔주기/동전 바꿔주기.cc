#include <bits/stdc++.h>
using namespace std;

int T, k;
// int coin[101][2];
int dp[101][10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    cin >> k;
    dp[0][0] = 1;
    for (int i = 1; i <= k; i++) {
        int p, n;
        cin >> p >> n;
        for (int j = 0; j <= T; j++) {
            for(int k=0;k<=n;k++){
                if(j-p*k<0) break;
                dp[i][j]+=dp[i-1][j-p*k];
            }
        }
    }
    cout<<dp[k][T];
}