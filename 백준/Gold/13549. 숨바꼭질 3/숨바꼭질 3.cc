#include <bits/stdc++.h>
using namespace std;
bool visited[100001];
int N, K;
void bfs() {
    deque<pair<int, int> > q;
    visited[N] = true;
    q.push_front(make_pair(N, 0));
    while(!q.empty()){
        int next = q.front().first;
        int cnt = q.front().second;
        q.pop_front();
        if (next == K) {
            cout << cnt;
            return;
        }
        if (next * 2 <= 100000 && !visited[next * 2]) {
            visited[next * 2] = true;
            q.push_front(make_pair(next * 2, cnt));
        }
        if(next-1>=0&&!visited[next-1]){
            visited[next - 1] = true;
            q.push_back(make_pair(next - 1, cnt + 1));
        }
        if (next + 1 <= 100000 && !visited[next + 1]){
            visited[next +1] = true;
            q.push_back(make_pair(next + 1, cnt + 1));
        }
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    if(N>=K){
        cout << N - K;
    }else{
        bfs();
    }
}