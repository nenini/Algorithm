#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int parent[50001];
int depth[50001];
int N, M;
vector<int> vct[50001];
bool visited[50001];

int LCA(int a, int b) {
    while (depth[a] > depth[b]) a = parent[a];
    while (depth[b] > depth[a]) b = parent[b];

    while (a != b) {
        a = parent[a];
        b = parent[b];
    }
    return a;
}

void make_parent() {
    queue<int> q;

    parent[1] = 0;
    visited[1] = true;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < vct[cur].size(); i++) {
            int next = vct[cur][i];
            if (!visited[next]) {
                visited[next]=true;
                parent[next] = cur;
                depth[next] = depth[cur] + 1;
                q.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        vct[a].push_back(b);
        vct[b].push_back(a);
    }
    make_parent();
    cin >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        cout << LCA(a, b)<<"\n";
    }
}
