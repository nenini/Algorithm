#include <bits/stdc++.h>
using namespace std;
int k, n, T;
int dp[15][15];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> k >> n;
        for (int j = 0; j <= k;j++){
            for (int l = 1; l <= n;l++){
                if(j==0){
                    dp[j][l] = l;
                }else{
                    dp[j][l] = dp[j - 1][l] + dp[j][l - 1];
                }
            } 
        }
        cout << dp[k][n]<<"\n";
    }
}