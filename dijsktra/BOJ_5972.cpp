#include<bits/stdc++.h>
#define INF (int)1e9
using namespace std;
int N, M;
vector<pair<int, int> > vct[50001];
int result[50001];
void dijkstra(int start) { 
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0, start));
    result[start] = 0;
    while(!pq.empty()){
        int c = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        if(result[c]<w) continue;
        for (int i = 0; i < vct[c].size();i++){
            int new_c = vct[c][i].second;
            int new_w = w+vct[c][i].first;
            if(result[new_c]>new_w){
                result[new_c] = new_w;
                pq.push(make_pair(new_w, new_c));
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M;i++){
        int A, B, C;
        cin >> A >> B >> C;
        vct[A].push_back(make_pair(C, B));
        vct[B].push_back(make_pair(C, A));
    }
    for (int i = 0; i <= N;i++){
        result[i]=INF;
    }
    dijkstra(1);
    cout << result[N];
}