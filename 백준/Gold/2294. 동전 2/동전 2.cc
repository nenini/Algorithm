#include<iostream>
using namespace std;
int n, k;
int dp[10001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= k;i++){
        dp[i] = (int)1e9;
    }
    for (int i = 0; i < n;i++){
        int cost;
        cin >> cost;
        for (int j = cost; j <= k;j++){
            dp[j] = min(dp[j - cost]+1, dp[j]);
        }
    }
    if(dp[k]==(int)1e9){
        cout << -1;
    }else
        cout << dp[k];
}