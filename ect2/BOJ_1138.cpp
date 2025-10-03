#include <bits/stdc++.h>
using namespace std;
int N;
int arr[11];
vector<int> vct;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    for (int i = N; i >= 1; i--) {
        vct.insert(vct.begin() + arr[i], i);
    }
    for (int i = 0;i<N;i++) {
        cout << vct[i] << " ";
    }
}