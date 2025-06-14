#include <bits/stdc++.h>
#define INF (int)1e9
using namespace std;
int N, M;
vector<tuple<int, int, int> > edge;
long long dist[501];
int bellman(int start) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < edge.size(); j++) {
            int a = get<0>(edge[j]);
            int b = get<1>(edge[j]);
            int c = get<2>(edge[j]);
            if (dist[a] != INF && dist[a] + c < dist[b]) {
                dist[b] = dist[a] + c;
                if (i == N - 1) {
                    return false;
                }
            }
        }
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    while (M--) {
        int A, B, C;
        cin >> A >> B >> C;
        edge.push_back(make_tuple(A, B, C));
    }
    fill(dist, dist + 501, INF);
    dist[1] = 0;
    if (bellman(1) == false) {
        cout << "-1";
    } else {
        for (int i = 2; i <= N; i++) {
            if(dist[i]==INF){
                cout << "-1" << "\n";
            }else{
                cout << dist[i] << "\n";
            }
        }
    }
}