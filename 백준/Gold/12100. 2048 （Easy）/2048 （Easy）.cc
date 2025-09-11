#include <bits/stdc++.h>
using namespace std;
int N;
int arr[20][20];
int result = 0;
void arr_left() {
    for (int i = 0; i < N; i++) {
        vector<int> vct;
        vector<int> sum_vct;
        for (int j = 0; j < N; j++) {
            if(arr[i][j]!=0){
                vct.push_back(arr[i][j]);
                arr[i][j] = 0;
            }
        }
        for (int k = 0; k < vct.size();) {
            if (k + 1 < vct.size() && vct[k] == vct[k + 1]) {
                sum_vct.push_back(vct[k] * 2);
                k += 2;
            } else {
                sum_vct.push_back(vct[k]);
                k += 1;
            }
        }
        for (int j = 0; j < sum_vct.size();j++){
            arr[i][j] = sum_vct[j];
        }
    }
}
void arr_right() {
    for (int i = 0; i < N; i++) {
        vector<int> vct;
        vector<int> sum_vct;
        for (int j = N-1; j >=0; j--) {
            if (arr[i][j] != 0) {
                vct.push_back(arr[i][j]);
                arr[i][j] = 0;
            }
        }
        for (int k = 0; k < vct.size();) {
            if (k + 1 < vct.size() && vct[k] == vct[k + 1]) {
                sum_vct.push_back(vct[k] * 2);
                k += 2;
            } else {
                sum_vct.push_back(vct[k]);
                k += 1;
            }
        }
        for (int j = 0; j < sum_vct.size(); j++) {
            arr[i][N-j-1] = sum_vct[j];
        }
    }
}
void arr_up() {
    for (int i = 0; i < N; i++) {
        vector<int> vct;
        vector<int> sum_vct;
        for (int j = 0; j < N; j++) {
            if (arr[j][i] != 0) {
                vct.push_back(arr[j][i]);
                arr[j][i] = 0;
            }
        }
        for (int k = 0; k < vct.size();) {
            if (k + 1 < vct.size() && vct[k] == vct[k + 1]) {
                sum_vct.push_back(vct[k] * 2);
                k += 2;
            } else {
                sum_vct.push_back(vct[k]);
                k += 1;
            }
        }
        for (int j = 0; j < sum_vct.size(); j++) {
            arr[j][i] = sum_vct[j];
        }
    }
}
void arr_down() {
    for (int i = 0; i < N; i++) {
        vector<int> vct;
        vector<int> sum_vct;
        for (int j = N - 1; j >= 0; j--) {
            if (arr[j][i] != 0) {
                vct.push_back(arr[j][i]);
                arr[j][i] = 0;
            }
        }
        for (int k = 0; k < vct.size();) {
            if (k + 1 < vct.size() && vct[k] == vct[k + 1]) {
                sum_vct.push_back(vct[k] * 2);
                k += 2;
            } else {
                sum_vct.push_back(vct[k]);
                k += 1;
            }
        }
        for (int j = 0; j < sum_vct.size(); j++) {
            arr[N-j-1][i] = sum_vct[j];
        }
    }
}
void fun(int index) {
    if (index == 5) {
        int max_num = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                max_num = max(max_num, arr[i][j]);
            }
        }
        result = max(max_num, result);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int copy[20][20];
        memcpy(copy, arr, sizeof(arr));
        if (i == 0) {
            arr_left();
        } else if (i == 1) {
            arr_right();
        } else if (i == 2) {
            arr_up();
        } else {
            arr_down();
        }
        fun(index + 1);
        memcpy(arr, copy, sizeof(arr));
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
    fun(0);
    cout << result;
}