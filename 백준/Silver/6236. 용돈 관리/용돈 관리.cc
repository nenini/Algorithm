#include <bits/stdc++.h>
using namespace std;
int N, M;
int arr[100000];
bool check(int num) {
    int sum = 0;
    int count = 1;
    for (int i = 0; i < N; i++) {
        if (arr[i] > num) return false;
        if (sum + arr[i] <= num) {
            sum += arr[i];
        } else {
            sum = arr[i];
            count++;
        }
    }
    if (M >= count) {
        return true;
    } else {
        return false;
    }
}

int binary_search(int start, int end) {
    int result = 0;
    while (start <= end) {
        int middle = (start + end) / 2;
        if (check(middle)) {
            end = middle - 1;
            result = middle;
        } else {
            start = middle + 1;
        }
    }
    return result;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    int sum=0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        sum+=arr[i];

    }
    int max_num= *max_element(arr, arr + N);
    cout << binary_search(max_num, sum);
}