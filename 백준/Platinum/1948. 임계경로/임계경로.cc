#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int> > road[10001];
vector<pair<int, int> > reverse_road[10001];
int indegree[10001];
int dp[10001];
int road_num;
int start, finish;
bool visited[10001];

void topology() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int i = 0; i < road[curr].size(); i++) {
            int next = road[curr][i].first;
            int weight = road[curr][i].second;
            dp[next] = max(dp[next], dp[curr] + weight);
            if (--indegree[next] == 0) {
                q.push(next);
            }
        }
    }
}

void fun() {
    queue<int> q;
    q.push(finish);
    visited[finish]=true;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int i = 0; i < reverse_road[curr].size(); i++) {
            int next = reverse_road[curr][i].first;
            int weight = reverse_road[curr][i].second;
            if (dp[next] + weight == dp[curr]) {
                if (!visited[next]) {
                    q.push(next);
                    visited[next]=true;
                }
                road_num++;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        road[u].push_back(make_pair(v, w));
        reverse_road[v].push_back(make_pair(u, w));

        indegree[v]++;
    }
    cin >> start >> finish;
    topology();
    fun();
    cout << dp[finish] << "\n";
    cout << road_num;
}