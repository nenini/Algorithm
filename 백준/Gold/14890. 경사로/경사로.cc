#include <bits/stdc++.h>
using namespace std;
int N, L;
int arr[100][100];
bool visited[100];
int result;
int main() {
    ios::sync_with_stdio(false);
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        memset(visited, false, sizeof(visited));
        bool all = true;
        for (int j = 0; j < N - 1;) {
            bool check = false;
            if (arr[i][j] == arr[i][j + 1] + 1) {
                // j가 j+1보다 1 클때->낮아짐
                if (j + L >= N) {
                    all = false;
                    break;
                }
                if (L == 1 && visited[j+1]) check = true;
                for (int k = j + 1; k < j + L; k++) {
                    if (arr[i][k] != arr[i][k + 1] || visited[k] || visited[k + 1]) {
                        check = true;
                    } 
                }
                if (!check) {
                    for (int k = j + 1;k<=j+L;k++){
                        visited[k]=true;
                    } 
                    j += L;
                } else {
                    all = false;
                    break;
                }

            } else if (arr[i][j] == arr[i][j + 1] - 1) {
                // j가 j+1보다 1 작을때->커짐
                if (j - L + 1 < 0) {
                    all = false;
                    break;
                }
                if (L == 1 && visited[j]) check = true;
                for (int k = j; k > j - L + 1; k--) {
                    if (arr[i][k] != arr[i][k - 1] || visited[k] || visited[k - 1]) {
                        check = true;
                    } 
                }
                if (!check) {
                    for (int k = j ; k > j - L; k--) {
                        visited[k] = true;
                    }
                    j++;
                } else {
                    all = false;
                    break;
                }
            } else if (arr[i][j] == arr[i][j + 1]) {
                j++;
            } else {
                all = false;
                break;
            }
        }
        if (all) {
            result++;
        }
    }
    for (int i = 0; i < N; i++) {
        memset(visited, false, sizeof(visited));

        bool all = true;

        for (int j = 0; j < N - 1;) {
            bool check = false;
            if (arr[j][i] == arr[j + 1][i] + 1) {
                // j가 j+1보다 1 클때->낮아짐
                if (j + L >= N) {
                    all = false;
                    break;
                }
                for (int k = j + 1; k < j + L; k++) {
                    if (arr[k][i] != arr[k + 1][i] || visited[k] || visited[k + 1]) {
                        check = true;
                    } 
                }
                if (!check) {
                    for (int k = j + 1; k <= j + L; k++) {
                        visited[k] = true;
                    }
                    j += L;
                } else {
                    all = false;
                    break;
                }

            } else if (arr[j][i] == arr[j + 1][i] - 1) {
                // j가 j+1보다 1 작을때->커짐
                if (j - L + 1 < 0) {
                    all = false;
                    break;
                }
                if (L == 1 && visited[j]) check = true;
                for (int k = j; k > j - L + 1; k--) {
                    if (arr[k][i] != arr[k - 1][i] || visited[k] || visited[k - 1]) {
                        check = true;
                    } 
                }
                if (!check) {
                    for (int k = j; k > j - L; k--) {
                        visited[k] = true;
                    }
                    j++;
                } else {
                    all = false;
                    break;
                }
            } else if (arr[j][i] == arr[j + 1][i]) {
                j++;
            } else {
                all = false;
                break;
            }
        }
        if (all) {
            result++;
        }
    }
    cout << result;
}