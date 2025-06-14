#include <bits/stdc++.h>
#define INF (int)1e9
using namespace std;
int TC, N, M, W;
vector<pair<int, pair<int, int> > > vct;
int dist[501];
bool Bellman(int start) {
    for (int i = 0; i < N ; i++) {
        for (int j = 0; j < vct.size();j++){
            int s = vct[j].first;
            int e = vct[j].second.first;
            int t = vct[j].second.second;
            // if(dist[s]!=INF&&dist[s]+t<dist[e]){
            //     dist[e] = dist[s] + t;
            //     if (i == N - 1) return true;
            // }
            if (dist[s] + t < dist[e]) {
                dist[e] = dist[s] + t;
                if (i == N - 1) return true;
            }
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> TC;
    while (TC--) {
        cin >> N >> M >> W;
        int S, E, T;
        vct.clear();
        for (int i = 0; i < M; i++) {
            cin >> S >> E >> T;
            vct.push_back(make_pair(S, make_pair(E, T)));
            vct.push_back(make_pair(E, make_pair(S, T)));
        }
        for (int i = 0; i < W; i++) {
            cin >> S >> E >> T;
            vct.push_back(make_pair(S, make_pair(E, -T)));
        }
        fill(dist, dist + 501, INF);
        // dist[1] = 0;
        if(Bellman(1)){
            cout << "YES" << "\n";
        }else{
            cout << "NO" << "\n";
        }
    }
}