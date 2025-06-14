#include <bits/stdc++.h>
#define INF 987654321
using namespace std;
int n, m;
int dist[101][101];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        fill(dist[i]+1, dist[i] + n + 1, INF);
        dist[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF) cout << 0 ;
            else
                cout << dist[i][j] ;
            if (j < n) cout << " ";
        }
        cout << "\n";
    }
}