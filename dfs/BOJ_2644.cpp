#include <bits/stdc++.h>
using namespace std;
int visited[101];
vector<int> vct[100];
int n, p1, p2, m;
bool check;
void dfs(int start) {
    if(start==p2){
        cout<<visited[p2];
        check = true;
        return;
    }
    for (int i = 0; i < vct[start].size();i++){
        int curr = vct[start][i];
        if(!visited[curr]){
            visited[curr] = visited[start] + 1;
            dfs(curr);
            if (check) return;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> p1 >> p2 >> m;
    for (int i = 0; i < m;i++){
        int x, y;
        cin >> x >> y;
        vct[x].push_back(y);
        vct[y].push_back(x);
    }
    dfs(p1);
    if (!check) cout << -1;
}