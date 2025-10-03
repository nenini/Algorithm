#include <bits/stdc++.h>
using namespace std;
int N;
int arr[8];
bool visited[8];
vector<int> selected;
int result=INT_MIN;
void dfs(int idx) {
    if (idx == N) {
        int sum=0;
        for (int i = 0; i < N - 1; i++) {
            sum += abs(selected[i] - selected[i + 1]);
        }
        result = max(sum, result);
        return;
    }
    for (int i = 0; i < N;i++){
        if(!visited[i]){
            visited[i] = true;
            selected.push_back(arr[i]);
            dfs(idx + 1);
            selected.pop_back();
            visited[i] = false;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    dfs(0);
    cout << result;
}