#include <bits/stdc++.h>
using namespace std;
int N, K;
int arr[1000000];
int sum;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N;i++){
        cin >> arr[i];
    }
    for (int i = N - 1;i>=0;i--){
        if(arr[i]<=K){
            int num = K / arr[i];
            sum += num;
            K -= num * arr[i];
        }
        if(K==0){
            cout << sum;
            return 0;
        }
    }
}