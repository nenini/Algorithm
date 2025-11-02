#include <bits/stdc++.h>
using namespace std;
int T, N, M;
int arr[100]; 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;

    while (T--) {
        cin >> N >> M;

        queue<int> q1;
        queue<int> q2;

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            q1.push(i);  
        }

        int result = 1;

        while (true) {
            int size = q1.size();
            int max_num = -1;
            int max_index = -1;
            for (int i = 0; i < size; i++) {
                if (arr[q1.front()] > max_num) {
                    max_num = arr[q1.front()];
                    max_index = q1.front();
                }
                q2.push(q1.front());
                q1.pop();
            }
            if (max_index == M) {
                cout << result<<"\n";
                break;
            }

            for (int i = 0; i < size; i++) {
                if (arr[q2.front()] == max_num) {
                    q2.pop();
                    int size1 = q1.size();
                    for (int j = 0; j < size1; j++) {
                        q2.push(q1.front());
                        q1.pop();
                    }
                    result++;
                    swap(q1, q2);
                    break;
                } else {
                    q1.push(q2.front());
                    q2.pop();
                }
            }
        }
    }
}