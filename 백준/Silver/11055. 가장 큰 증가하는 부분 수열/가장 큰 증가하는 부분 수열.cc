#include<iostream>
using namespace std;
int N;
int arr[1001];
int dp[1001];
int sum = 0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N;i++){
        cin >> arr[i];
        dp[i] = arr[i];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
        sum = max(sum, dp[i]);
    }
    cout << sum;
}