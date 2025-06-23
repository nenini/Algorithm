#include <bits/stdc++.h>
using namespace std;
int N;
int T[16];
int P[16];
int dp[17];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N;i++){
        cin >> T[i] >> P[i];
    }
    for (int i = 1; i <= N+1; i++) {
        dp[i] = max(dp[i], dp[i - 1]);
        if(i+T[i]<=N+1){
            dp[i + T[i]] = max(dp[i + T[i]], dp[i]+P[i]);
        }
        // for (int i = 1; i <= N+1; i++){
        //     cout << dp[i]<<" ";
        // }
   }
    cout << dp[N+1];
}
