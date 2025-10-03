#include <bits/stdc++.h>
using namespace std;
vector<int> arr[101];
int N, M;
int min_num=(int)1e9;
int min_index;
int visited[101];
int bfs(int start) {
    memset(visited, -1, sizeof(visited));
    queue<int> q;
    q.push(start);
    visited[start] = 0;
    int total = 0;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for (int i = 0; i < arr[curr].size(); i++) {
            int next = arr[curr][i];
            if(visited[next]==-1){
                visited[next] = visited[curr] + 1;
                total += visited[next];
                q.push(next);
            }
        }
    }
    return total;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        arr[A].push_back(B);
        arr[B].push_back(A);
    }
    for (int i = 1; i <= N;i++){
        int num = bfs(i);
        if (min_num > num) {
            min_num = num;
            min_index = i;
        }
    }
    cout << min_index;
}