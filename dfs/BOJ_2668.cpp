#include<bits/stdc++.h>
using namespace std;
int N;
int arr[101];
bool visited[101];
vector<int> result;
void dfs(int start, int curr) { 
    if(visited[curr]){
        if(start==curr){
            result.push_back(start);
        }
        return;
    }
    visited[curr] = true;
    dfs(start, arr[curr]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 1;i<=N;i++){
        cin>>arr[i];
    }
    for (int i = 1; i <= N; i++) {
        fill(visited, visited + N + 1, false);
        dfs(i,i);
    }
    cout << result.size() << "\n";
    sort(result.begin(), result.end());
    for (int i = 0; i < result.size();i++){
        cout << result[i] << "\n";
    } }