#include <bits/stdc++.h>
using namespace std;
int K;
bool visited[20001];
bool color[20001];
vector<int> vct[20001];
bool check = false;

void dfs(int num, bool curr_color) {
    visited[num]=true;
    color[num] = curr_color;
    for (int i = 0; i < vct[num].size(); i++) {
        int next = vct[num][i];
        if (visited[next]&&color[next]==curr_color){
            check=true;
            return;
        }
        if (!visited[next]){
            dfs(next,!curr_color);
        } 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> K;

    for (int i = 0; i < K; i++) {
        check = false;
        int V, E;
        cin >> V >> E;
        fill(visited, visited + V + 1, false);
        fill(color, color + V + 1, false);
        for (int i = 1; i <= V; ++i) vct[i].clear();

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            vct[u].push_back(v);
            vct[v].push_back(u);
        }

        for (int i = 1; i <= V; i++) {
            if (check) {
                break;
            }
            if (!visited[i]) {
                dfs(i, true);
            }
        }
        if(check) cout<<"NO\n";
        else cout<<"YES\n";
    }
}