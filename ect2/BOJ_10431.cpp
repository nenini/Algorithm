#include <bits/stdc++.h>
using namespace std;
int arr[20];
int P;
void fun(int total, int end) {
    for (int i = end - 1; i >= end-total; i--) {
        arr[i + 1] = arr[i];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> P;
    for (int i = 0; i < P; i++) {
        int sum = 0;
        int a;
        cin >> a;
        cin >> arr[0];
        for (int j = 1; j < 20; j++) {
            int input;
            cin >> input;
            for (int k = 0; k < j; k++) {
                if (input < arr[k]) {
                    int num = j - k;
                    sum += num;
                    fun(num, j);
                    arr[k] = input;
                    break;
                }else{
                    arr[j] = input;
                }
            }
        }
        cout << i + 1 << " " << sum << "\n";
    }
}