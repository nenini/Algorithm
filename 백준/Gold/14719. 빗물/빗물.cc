#include <bits/stdc++.h>
using namespace std;
int H, W;
int arr[500];
int result;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> H >> W;
    for (int i = 0; i < W; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i < W - 1;i++){
        int left_max=0, right_max=0;
        for(int j=0;j<i;j++){
            left_max = max(arr[j], left_max);
        }
        for (int j = i + 1; j < W;j++){
            right_max = max(arr[j], right_max);
        }
        int min_num = min(left_max, right_max);
        if(arr[i]<min_num){
            result += min_num - arr[i];
        }
    }
    cout << result;
}