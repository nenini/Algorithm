#include <bits/stdc++.h>
#define INF (int)1e7
using namespace std;
int N, E;
int v1, v2;
int result[801];
vector<pair<int, int> > vct[801];
void dijstra(int start) {
    for (int i = 0; i <= N; i++) {
        result[i] = INF;
    }
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    result[start] = 0;
    pq.push(make_pair(0, start));  // weight,u
    while (!pq.empty()) {
        int curr = pq.top().second;
        int weight = pq.top().first;
        pq.pop();
        if (result[curr] < weight) continue;
        for (int i = 0; i < vct[curr].size(); i++) {
            int new_curr = vct[curr][i].second;
            int new_weight = weight + vct[curr][i].first;
            if (new_weight < result[new_curr]) {
                result[new_curr] = new_weight;
                pq.push(make_pair(new_weight, new_curr));
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> E;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        vct[u].push_back(make_pair(w, v));
        vct[v].push_back(make_pair(w, u));
    }
    cin >> v1 >> v2;
    dijstra(1); //1->v1, 1->v2
    int start_v1 = result[v1];
    int start_v2 = result[v2];
    dijstra(v1); //v1->v2, v1->N
    int v1_v2 = result[v2];  // v1->v2==v2->v1
    int v1_end = result[N];
    dijstra(v2);
    int v2_end = result[N];
    int answer = min(start_v1 + v1_v2 + v2_end, start_v2 + v1_v2 + v1_end);
    if (answer >= INF) {
        cout << -1;
    }else{
        cout << answer;
    }
}