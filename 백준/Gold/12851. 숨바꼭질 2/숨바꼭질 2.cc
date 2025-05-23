#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
int N, K;
int dist[MAX];  
int cnt[MAX];   

void bfs() {
    queue<int> q;
    dist[N] = 0;
    cnt[N] = 1;
    q.push(N);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : {cur - 1, cur + 1, cur * 2}) {
            if (next < 0 || next >= MAX) continue;
            if (dist[next] == -1) {
                dist[next] = dist[cur] + 1;
                cnt[next] = cnt[cur];
                q.push(next);
            } else if (dist[next] == dist[cur] + 1) {
                cnt[next] += cnt[cur];
            }
        }
    }

    cout << dist[K] << "\n" << cnt[K] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;

    fill(dist, dist + MAX, -1);  
    bfs();
}
