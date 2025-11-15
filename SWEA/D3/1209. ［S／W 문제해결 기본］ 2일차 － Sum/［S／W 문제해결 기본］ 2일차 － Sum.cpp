#include <bits/stdc++.h>

using namespace std;
int arr[100][100];
long long result;

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int test = 1; test <= 10; test++) {
        result = 0;
        int testnum;
        cin >> testnum;
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                cin >> arr[i][j];
            }
        }

        long long sum = 0;
        for (int i = 0; i < 100; i++) {
            sum = 0;
            for (int j = 0; j < 100; j++) {
                sum += arr[i][j];
            }
            result = max(result, sum);
        }
        for (int i = 0; i < 100; i++) {
            sum = 0;
            for (int j = 0; j < 100; j++) {
                sum += arr[j][i];
            }
            result = max(result, sum);
        }
        sum = 0;
        for (int i = 0; i < 100; i++) {
            sum += arr[i][i];
        }
        result = max(result, sum);

        sum = 0;
        for (int i = 0; i < 100; i++) {
            sum += arr[i][99 - i];
        }
        result = max(result, sum);
        cout << "#" << testnum << " " << result << "\n";
    }
    return 0;  // 정상종료시 반드시 0을 리턴해야합니다.
}