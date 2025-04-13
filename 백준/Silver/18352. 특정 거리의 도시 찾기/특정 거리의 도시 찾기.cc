#include <bits/stdc++.h>
#define INF (int)1e9
using namespace std;
int N, M, K, X;
vector<pair<int, int> > vct[300001];
int result[300001];
void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    result[start] = 0;
    pq.push(make_pair(0,start));
    while(!pq.empty()){
        int c = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        if(result[c]<w) continue;
        for (int i = 0; i < vct[c].size();i++){
            int nc = vct[c][i].second;
            int nw = w+vct[c][i].first;
            if(result[nc]>nw){
                result[nc] = nw;
                pq.push(make_pair(nw, nc));
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M >> K >> X;
    for (int i = 0; i < M;i++){
        int A, B;
        cin >> A >> B;
        vct[A].push_back(make_pair(1,B));
    }
    for (int i = 0; i <= N; i++) {
        result[i] = INF;
    }
    dijkstra(X);
    bool check = false;
    for (int i = 1; i <= N; i++) {
        if(result[i]==K){
            cout << i << "\n";
            check = true;
        }
    }
    if(check==false){
        cout << -1;
    }
}
