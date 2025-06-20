#include<bits/stdc++.h>
using namespace std;
int N, M;
int arr[101];
bool visited[101];
void bfs(int start, int depth) {
    queue<pair<int, int> > q;
    visited[start] = true;
    q.push(make_pair(arr[start], depth));
    while(!q.empty()){
        int curr=q.front().first;
        int cur_depth = q.front().second;
        q.pop();
        if (curr == 100) {
            cout << cur_depth;
            return;
        }
        for (int i = 1; i <= 6;i++){
            int next = curr + i;
            if (next > 100) continue;
            if (!visited[next]) {
                q.push(make_pair(arr[next], cur_depth + 1));
                visited[next] = true;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 1;i<=100;i++){
        arr[i] = i;
    }
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        arr[x] = y;
    }
    for (int i = 0; i < M; i++) {
        int u,v;
        cin >> u >>v;
        arr[u] = v;
    }
    bfs(1, 0);
}