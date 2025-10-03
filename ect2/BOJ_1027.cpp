#include <bits/stdc++.h>
using namespace std;
int N;
int arr[51];
int result;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= N; i++) {
        int num = 0;
        for (int j = 1; j <= N; j++) {
            bool check=false;
            if(i!=j){
                int lenght = arr[j] - arr[i];
                int dist = j - i;
                for (int k = min(i, j) + 1; k < max(i, j); k++){
                    double height = arr[i] + (double)lenght * (k - i) / dist;
                    if (height <= arr[k]) {
                        check = true;
                        break;
                    }
                }
                if (!check) {
                    num++;
                }
            }
        }
        result = max(result, num);
    }
    cout << result;
}