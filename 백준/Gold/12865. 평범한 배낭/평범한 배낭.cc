#include<iostream>
using namespace std;
int N, K;
int dp[101][100001];
int w[101];
int v[101];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    for (int i = 1;i<=N;i++){
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= N;i++){
        for (int j = 1; j <= K;j++){
            if(w[i]<=j){
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            }else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[N][K];
}