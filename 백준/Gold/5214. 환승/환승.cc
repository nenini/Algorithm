#include <bits/stdc++.h>
#define INF (int)1e9
using namespace std;
int dp[101001];
vector<int> vct[101001];
int N, K, M;

int bfs() {
    queue<int> q;
    dp[1] = 1;
    q.push(1);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (curr == N) {
            return (dp[curr]+1)/2;
        }
        for (int i = 0; i < vct[curr].size(); i++) {
            int next = vct[curr][i];
            if (dp[next] > dp[curr] + 1) {
                dp[next] = dp[curr] + 1;
                q.push(next);
            }
        }
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K >> M;
    fill(dp,dp+N+M+1,INF);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            int a;
            cin >> a;
            int h=N+i+1;
            vct[a].push_back(h);
            vct[h].push_back(a);
        }
    }
    cout << bfs();
}