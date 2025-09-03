#include <bits/stdc++.h>
using namespace std;
int N, D;
int arr[10001];
vector<pair<int, int> > vct[10001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> D;
    for (int i = 0; i < N; i++) {
        int start, end, dist;
        cin >> start >> end >> dist;
        vct[end].push_back(make_pair(start, dist));
    }
    for (int i = 1; i <= D; i++) {
        arr[i] = arr[i - 1] + 1;
        for (int j = 0; j < vct[i].size(); j++) {
            arr[i] = min(arr[i], arr[vct[i][j].first] + vct[i][j].second);
        }
    }
    cout << arr[D];
}