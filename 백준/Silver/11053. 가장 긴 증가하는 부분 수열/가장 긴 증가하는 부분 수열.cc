#include<iostream>
#include<algorithm>
using namespace std;
int N;
int arr[1001];
int dp[1001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    int num;
    for (int i = 0; i < N; i++)
    {
        cin>>arr[i];
        dp[i] = 1;
    }
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i;j++){
            if(arr[i]>arr[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        sum = max(sum, dp[i]);
    }
    cout << sum;
}