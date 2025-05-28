#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int> > vct[10001];
bool visited[10001];
int max_dist, next_node;
void dfs(int start, int dist) { 
    visited[start] = true;
    if(dist>max_dist){
        max_dist = dist;
        next_node = start;
    }
    for (int i = 0; i < vct[start].size();i++){
        int weight = dist + vct[start][i].first;
        int next = vct[start][i].second;
        if (!visited[next]){
            dfs(next, weight);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        vct[x].push_back(make_pair(w, y));
        vct[y].push_back(make_pair(w, x));
    }
    dfs(1,0);
    max_dist = 0;
    fill(visited, visited + n+1, false);
    dfs(next_node, 0);
    cout << max_dist;
}