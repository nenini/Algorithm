// #include <bits/stdc++.h>
// using namespace std;
// int N;
// int arr[20][20];
// int result = 0;

// void arr_left() {
//     for (int i = 0; i < N; i++) {
//         int index = 0;
//         vector<int> vct;
//         vct.reserve(N);
//         vector<int> sum_vct;
//         sum_vct.reserve(N);
//         for (int j = 0; j < N; j++) {
//             if (arr[i][j] != 0) {
//                 vct.push_back(arr[i][j]);
//                 arr[i][j] = 0;
//             }
//         }
//         for (int k = 0; k < vct.size();) {
//             if (k + 1 < vct.size() && vct[k] == vct[k + 1]) {
//                 sum_vct.push_back(vct[k] * 2);
//                 k += 2;
//             } else {
//                 sum_vct.push_back(vct[k]);
//                 k += 1;
//             }
//         }
//         for (int j = 0; j < sum_vct.size(); j++) {
//             arr[i][j] = sum_vct[j];
//         }
//     }
// }
// void arr_right() {
//     for (int i = 0; i < N; i++) {
//         vector<int> vct;
//         vct.reserve(N);
//         vector<int> sum_vct;
//         sum_vct.reserve(N);
//         for (int j = N - 1; j >= 0; j--) {
//             if (arr[i][j] != 0) {
//                 vct.push_back(arr[i][j]);
//                 arr[i][j] = 0;
//             }
//         }
//         for (int k = 0; k < vct.size();) {
//             if (k + 1 < vct.size() && vct[k] == vct[k + 1]) {
//                 sum_vct.push_back(vct[k] * 2);
//                 k += 2;
//             } else {
//                 sum_vct.push_back(vct[k]);
//                 k += 1;
//             }
//         }
//         for (int j = 0; j < sum_vct.size(); j++) {
//             arr[i][N - j - 1] = sum_vct[j];
//         }
//     }
// }
// void arr_up() {
//     for (int i = 0; i < N; i++) {
//         vector<int> vct;
//         vct.reserve(N);
//         vector<int> sum_vct;
//         sum_vct.reserve(N);
//         for (int j = 0; j < N; j++) {
//             if (arr[j][i] != 0) {
//                 vct.push_back(arr[j][i]);
//                 arr[j][i] = 0;
//             }
//         }
//         for (int k = 0; k < vct.size();) {
//             if (k + 1 < vct.size() && vct[k] == vct[k + 1]) {
//                 sum_vct.push_back(vct[k] * 2);
//                 k += 2;
//             } else {
//                 sum_vct.push_back(vct[k]);
//                 k += 1;
//             }
//         }
//         for (int j = 0; j < sum_vct.size(); j++) {
//             arr[j][i] = sum_vct[j];
//         }
//     }
// }
// void arr_down() {
//     for (int i = 0; i < N; i++) {
//         vector<int> vct;
//         vct.reserve(N);
//         vector<int> sum_vct;
//         sum_vct.reserve(N);
//         for (int j = N - 1; j >= 0; j--) {
//             if (arr[j][i] != 0) {
//                 vct.push_back(arr[j][i]);
//                 arr[j][i] = 0;
//             }
//         }
//         for (int k = 0; k < vct.size();) {
//             if (k + 1 < vct.size() && vct[k] == vct[k + 1]) {
//                 sum_vct.push_back(vct[k] * 2);
//                 k += 2;
//             } else {
//                 sum_vct.push_back(vct[k]);
//                 k += 1;
//             }
//         }
//         for (int j = 0; j < sum_vct.size(); j++) {
//             arr[N - j - 1][i] = sum_vct[j];
//         }
//     }
// }

// void fun(int index) {
//     int max_num = 0;
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//             max_num = max(max_num, arr[i][j]);
//         }
//     }
//     result = max(result, max_num);

//     if (index == 10) {
//         return;
//     } else {
//         int remain = 10 - index;
//         long long optimistic = 1LL * max_num << remain;
//         if (optimistic <= result) return;
//     }

//     for (int i = 0; i < 4; i++) {
//         int copy[20][20];
//         memcpy(copy, arr, sizeof(arr));
//         if (i == 0)
//             arr_left();
//         else if (i == 1)
//             arr_up();
//         else if (i == 2)
//             arr_right();
//         else
//             arr_down();

//         if (memcmp(arr, copy, sizeof(arr)) != 0) {
//             fun(index + 1);
//         }
//         memcpy(arr, copy, sizeof(arr));
//     }
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cin >> N;
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//             cin >> arr[i][j];
//         }
//     }
//     fun(0);
//     cout << result;
// }

#include <bits/stdc++.h>
using namespace std;
int N;
int arr[20][20];
int result = 0;
int num;

void arr_left() {
    for (int i = 0; i < N; i++) {
        num = 0;
        vector<int> vct;
        vct.reserve(N);
        for (int j = 0; j < N; j++) {
            if (arr[i][j] != 0) {
                vct.push_back(arr[i][j]);
                arr[i][j] = 0;
            }
        }
        for (int k = 0; k < vct.size();) {
            if (k + 1 < vct.size() && vct[k] == vct[k + 1]) {
                arr[i][num] = vct[k] * 2;
                k += 2;
            } else {
                arr[i][num] = vct[k];
                k += 1;
            }
            num++;
        }
    }
}
void arr_right() {
    for (int i = 0; i < N; i++) {
        num = 0;
        vector<int> vct;
        vct.reserve(N);
        for (int j = N - 1; j >= 0; j--) {
            if (arr[i][j] != 0) {
                vct.push_back(arr[i][j]);
                arr[i][j] = 0;
            }
        }
        for (int k = 0; k < vct.size();) {
            if (k + 1 < vct.size() && vct[k] == vct[k + 1]) {
                arr[i][N - num - 1] = vct[k] * 2;
                k += 2;
            } else {
                arr[i][N - num - 1] = vct[k];
                k += 1;
            }
            num++;
        }
    }
}
void arr_up() {
    for (int i = 0; i < N; i++) {
        num = 0;
        vector<int> vct;
        vct.reserve(N);
        for (int j = 0; j < N; j++) {
            if (arr[j][i] != 0) {
                vct.push_back(arr[j][i]);
                arr[j][i] = 0;
            }
        }
        for (int k = 0; k < vct.size();) {
            if (k + 1 < vct.size() && vct[k] == vct[k + 1]) {
                arr[num][i] = vct[k] * 2;
                k += 2;
            } else {
                arr[num][i] = vct[k];
                k += 1;
            }
            num++;
        }
    }
}
void arr_down() {
    for (int i = 0; i < N; i++) {
        num = 0;
        vector<int> vct;
        vct.reserve(N);
        for (int j = N - 1; j >= 0; j--) {
            if (arr[j][i] != 0) {
                vct.push_back(arr[j][i]);
                arr[j][i] = 0;
            }
        }
        for (int k = 0; k < vct.size();) {
            if (k + 1 < vct.size() && vct[k] == vct[k + 1]) {
                arr[N - num - 1][i] = vct[k] * 2;
                k += 2;
            } else {
                arr[N - num - 1][i] = vct[k];
                k += 1;
            }
            num++;
        }
    }
}

void fun(int index) {
    int max_num = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            max_num = max(max_num, arr[i][j]);
        }
    }
    result = max(result, max_num);

    if (index == 10) {
        return;
    } else {
        int remain = 10 - index;
        long long optimistic = 1LL * max_num << remain;
        if (optimistic <= result) return;
    }

    for (int i = 0; i < 4; i++) {
        int copy[20][20];
        memcpy(copy, arr, sizeof(arr));
        if (i == 0)
            arr_left();
        else if (i == 1)
            arr_up();
        else if (i == 2)
            arr_right();
        else
            arr_down();

        if (memcmp(arr, copy, sizeof(arr)) != 0) {
            fun(index + 1);
        }
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