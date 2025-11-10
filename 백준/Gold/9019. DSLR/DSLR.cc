#include <bits/stdc++.h>
using namespace std;
int T;
bool visited[10000];
int arr[10000];
char arr2[10000];
// 01:33
void bfs(int curr, int B) {
    queue<int> q;
    q.push(curr);
    visited[curr] = true;
    while (!q.empty()) {
        int n = q.front();
        q.pop();
        if (n == B) {
            break;
        }
        for (int i = 0; i < 4; i++) {
            int num = 0;
            char dslr;
            if (i == 0) {
                if (2 * n > 9999) {
                    num = (2 * n) % 10000;
                } else {
                    num = n * 2;
                }
                dslr = 'D';
            } else if (i == 1) {
                if (n == 0) {
                    num = 9999;
                } else {
                    num = n - 1;
                }
                dslr = 'S';
            } else if (i == 2) {
                num = (n % 1000) * 10 + n / 1000;
                dslr = 'L';

            } else {
                num = (n % 10) * 1000 + n / 10;
                dslr = 'R';
            }
            if (visited[num]) continue;
            visited[num] = true;
            arr[num] = n;
            arr2[num] = dslr;
            q.push(num);
        }
    }
    string path;
    int start = B;
    while (true) {
        if (arr[start] == -1) {
            break;
        }
        path += arr2[start];

        start = arr[start];
    }
    reverse(path.begin(), path.end());
    cout << path << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for (int i = 0; i < T; i++) {
        int A, B;
        cin >> A >> B;
        fill(arr, arr + 10000, -1);
        fill(visited, visited + 10000, false);
        bfs(A, B);
    }
}