#include <bits/stdc++.h>
using namespace std;
int arr[200];
int dp[200];
int N;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N;i++){
        cin >> arr[i];
        dp[i] = 1;
    }
    for (int i = 0; i < N;i++){
        for (int j = 0;j<i;j++){
            if(arr[i]>arr[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        } 
    }
    int max_num = *max_element(dp, dp + N);
    cout << N - max_num;
}