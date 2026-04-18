#include <math.h>

#include <iostream>
#include <vector>
using namespace std;
int N;
vector<int> edge[1000001];
bool visited[1000001];
int dp[1000001][2];

void dfs(int cur_node) {
    dp[cur_node][0] = 1;
    dp[cur_node][1] = 0;
    visited[cur_node] = true;

    for (int i = 0; i < edge[cur_node].size(); i++) {
        int next = edge[cur_node][i];
        if (visited[next]) continue;
        dfs(next);
        dp[cur_node][0] += min(dp[next][0], dp[next][1]);
        dp[cur_node][1] += dp[next][0];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    dfs(1);
    cout << min(dp[1][0], dp[1][1]);
}