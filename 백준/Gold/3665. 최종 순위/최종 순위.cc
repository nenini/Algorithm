#include <climits>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int T, n, m;
vector<int> vct[501];
// int arr[501];
vector<int> arr;
int indegree[501];
bool score[501][501];
vector<int> result;

void topology() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int curr = q.front();
        result.push_back(curr);
        q.pop();
        for (int i = 0; i < vct[curr].size(); i++) {
            int next = vct[curr][i];
            if (score[curr][next] && --indegree[next] == 0) {
                q.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for (int t = 0; t < T; t++) {
        result.clear();
        for (int i = 0; i <= 500; i++) {
            vct[i].clear();
        }
        arr.clear();
        memset(indegree, 0, sizeof(indegree));
        memset(score, false, sizeof(score));
        cin >> n;
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            arr.push_back(t);
        }
        for (int i = 0; i < n; i++) {
            indegree[arr[i]] = i;
            for (int j = i + 1; j < n; j++) {
                vct[arr[i]].push_back(arr[j]);
                score[arr[i]][arr[j]] = true;  // 앞에가 순위 더 높음
            }
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            if (score[a][b]) {
                indegree[b]--;
                indegree[a]++;
                vct[b].push_back(a);
                score[a][b] = false;
                score[b][a] = true;
            } else {
                indegree[a]--;
                indegree[b]++;
                vct[a].push_back(b);
                score[a][b] = true;
                score[b][a] = false;
            }
        }
        topology();
        if (result.size() != n) {
            cout << "IMPOSSIBLE\n";
        } else {
            for (int i = 0; i < result.size(); i++) {
                cout << result[i] << " ";
            }
            cout << "\n";
        }
    }
}