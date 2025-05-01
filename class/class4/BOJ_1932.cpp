#include<iostream>
#include<algorithm>
using namespace std;
int n;
int num;
int arr[500][500]; 
int dp[500][500]; 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> arr[i][j];
        }
    }
    for (int j = 0; j < n; j++) {
        dp[n - 1][j] = arr[n - 1][j];
    }
    for (int i = n - 2; i >= 0; i--) {  
        for (int j = 0; j <= i; j++) {  
            dp[i][j] = arr[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }
    cout << dp[0][0];
}