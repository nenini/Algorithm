#include <bits/stdc++.h>
using namespace std;
int N;
int arr[21][21];
int total;
int result=INT_MAX;
vector<int> start;
void dfs(int index) {
    if (start.size() == N / 2) {
        vector<int> link;
        for (int i = 0; i <N; i++) {
            bool check = false;
            for (int j = 0; j < start.size(); j++) {
                if (i == start[j]) check = true;
            }
            if(!check){
                link.push_back(i);
            }
        }
        int start_sum = 0, link_sum = 0;
        for (int i = 0; i < N / 2;i++){
            for (int j = i+1; j < N / 2;j++){
                start_sum += arr[start[i]][start[j]] + arr[start[j]][start[i]];
                link_sum += arr[link[i]][link[j]] + arr[link[j]][link[i]];
            }
        }
        result = min(result, abs(link_sum-start_sum));
    }
    for (int i = index; i < N; i++) {
        start.push_back(i);
        dfs(i + 1);
        start.pop_back();
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (i != j) {
                total += arr[i][j];
            }
        }
    }
    dfs(0);
    cout << result;
}