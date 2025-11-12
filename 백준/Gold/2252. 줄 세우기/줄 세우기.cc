#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> vct[32001];
int indegree[32001];
vector<int> result;

void topology() {
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    for (int i = 1; i <= N; i++) {
        // if(q.empty())
        int curr = q.front();
        result.push_back(curr);
        q.pop();
        for (int j = 0; j < vct[curr].size(); j++) {
            int next = vct[curr][j];
            if (--indegree[next] == 0) {
                q.push(next);
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

    for (int i = 0; i < N; i++) {
        cout << result[i] << " ";
    }
}