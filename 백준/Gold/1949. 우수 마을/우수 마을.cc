#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N;
int population[10001];
vector<int> vct[10001];
int dp[10001][2];

void dfs(int curr_node, int parent) {
    dp[curr_node][0] = population[curr_node];  // 우수 마을 선택
    dp[curr_node][1] = 0;                      // 일반마을
    for (int i = 0; i < vct[curr_node].size(); i++) {
        int next = vct[curr_node][i];
        if (next == parent) continue;
        dfs(next, curr_node);
        dp[curr_node][0] += dp[next][1];                    // 우수일경우 다음 노드는 일반
        dp[curr_node][1] += max(dp[next][0], dp[next][1]);  // 일반일경우 다음 노드는 우수 또는 일반
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> population[i];
    }
    for (int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        vct[a].push_back(b);
        vct[b].push_back(a);
    }
    dfs(1, 0);
    cout << max(dp[1][0], dp[1][1]);
}