#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> vct[32001];
int indegree[32001];
vector<int> result;
void topology() {
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            pq.push(i);
        }
    }

    while (!pq.empty()) {
        int curr = pq.top();
        result.push_back(curr);
        pq.pop();
        for (int i = 0; i < vct[curr].size(); i++) {
            int next = vct[curr][i];
            if (--indegree[next] == 0) {
                pq.push(next);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        vct[a].push_back(b);
        indegree[b]++;
    }
    topology();
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
}