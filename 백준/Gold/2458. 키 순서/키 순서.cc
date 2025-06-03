#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> tall[501];
vector<int> shorts[501];
bool visited[501];
int cnt;
int result;
void dfs(int num, vector<int> vct[]) {
    visited[num] = true;
    for (int i = 0; i < vct[num].size();i++){
        if (!visited[vct[num][i]]) {
            dfs(vct[num][i], vct);
            cnt++;
        }
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        tall[x].push_back(y);
        shorts[y].push_back(x);
    }
    for (int i = 1; i <= N; i++) {
        cnt = 0;
        dfs(i, tall);
        fill(visited, visited + 501, false);
        dfs(i, shorts);
        if(cnt==N-1){
            result++;
        }
        fill(visited, visited + 501, false);
    }
    cout << result;
}