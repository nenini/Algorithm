#include <iostream>
#include <climits> // INT_MAX 사용
using namespace std;

int arr[100001];
int N, S;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int sum = 0;
    int minLen = INT_MAX;
    int L = 0, R = 0;

    while (true) {
        if (sum >= S) {
            minLen = min(minLen, R - L);
            sum -= arr[L++];
        } else if (R == N) {
            break;
        } else {
            sum += arr[R++];
        }
    }

    if (minLen == INT_MAX) cout << 0;
    else cout << minLen;
}
