#include <bits/stdc++.h>
using namespace std;
int N;
int A[50];
int B[50];
int sum;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N;i++){
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    sort(A, A + N);
    sort(B, B + N, greater<int>());
    for (int i = 0; i < N;i++){
        sum += A[i] * B[i];
    }
    cout << sum;
}