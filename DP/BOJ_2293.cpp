#include<iostream>
using namespace std;
int dp[10001]={1,};
int n, k;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int cost;
        cin >> cost;
        for (int j = 1; j <= k; j++)
        {
            if(j>=cost){
                dp[j] = dp[j] + dp[j - cost];
            }
        }
    }
    cout << dp[k];
}