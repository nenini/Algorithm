#include <bits/stdc++.h>
using namespace std;
int N, X;
int arr[250000];
int max_num;
int cnt;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> X;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int sum = 0;
    for (int i = 0; i < X; i++) 
        sum += arr[i];
    int max_num = sum;
    cnt = 1;
    for (int i = X; i < N; i++) {
        sum += arr[i] - arr[i - X];
        if (sum > max_num) {
            max_num = sum;
            cnt = 1;
        } else if (sum == max_num) {
            cnt++;
        }
    }
    if (max_num == 0) {
        cout << "SAD";
    } else {
        cout << max_num << "\n" << cnt;
    }
}