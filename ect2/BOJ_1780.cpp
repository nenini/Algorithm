#include <bits/stdc++.h>
using namespace std;
int N;
int arr[2187][2187];
int result[3];  //-1,0,1

void fun(int a, int b, int size) {
    bool skip=false;
    bool minusOne = false, zero = false, plusOne = false;
    for (int i = a; i < a + size; i++) {
        for (int j = b; j < b + size; j++) {
            if(arr[i][j]==-1){
                minusOne = true;
            } else if (arr[i][j] == 0) {
                zero = true;
            } else {
                plusOne = true;
            }
            if ((minusOne && zero) || (zero && plusOne) || (plusOne && minusOne)) {
                skip = true;
                break;
            }
        }
        if(skip){
            break;
        }
    }
    if ((minusOne && zero) ||(zero&&plusOne)||(plusOne&&minusOne)){
        fun(a, b, size / 3);
        fun(a, b + size / 3, size / 3);
        fun(a, b + size / 3 + size / 3, size / 3);
        fun(a + size / 3, b, size / 3);
        fun(a + size / 3, b + size / 3 + size / 3, size / 3);
        fun(a + size / 3, b + size / 3, size / 3);
        fun(a + size / 3 + size / 3, b, size / 3);
        fun(a + size / 3 + size / 3, b + size / 3, size / 3);
        fun(a + size / 3 + size / 3, b + size / 3 + size / 3, size / 3);
    }
    else{
        if (minusOne) {
            result[0]++;
        } else if (zero) {
            result[1]++;
        } else {
            result[2]++;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    fun(0, 0, N);
    for (int i = 0; i < 3;i++){
        cout << result[i] << "\n";
    }
}