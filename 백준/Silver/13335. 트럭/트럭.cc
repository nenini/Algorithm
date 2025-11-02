#include <bits/stdc++.h>
using namespace std;
int n, w, L;
int arr[1000];
int result = 0;
int sum;
int curr;
queue<int> q;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> w >> L;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    q.push(arr[0]);
    result++;
    sum += arr[0];
    curr = 1;
    while ((curr < n || !q.empty()) && sum != 0) {
        if (q.size() == w) {
            sum -= q.front();
            q.pop();
        }
        if (curr < n && sum + arr[curr] <= L) {
            q.push(arr[curr]);
            sum += arr[curr];
            curr++;
        } else {
            q.push(0);
        }
        result++;
    }
    cout << result;
}