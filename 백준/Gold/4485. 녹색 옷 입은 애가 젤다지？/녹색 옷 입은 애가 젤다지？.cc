#include<bits/stdc++.h>
#define INF (int)1e9
using namespace std;
int N;
int arr[126][126];
int dist[126][126];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
int num = 1;
void dijkstra() {
    priority_queue < pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;
    dist[0][0] = arr[0][0];
    pq.push(make_pair(dist[0][0], make_pair(0, 0)));
    while(!pq.empty()){
        int currx = pq.top().second.first;
        int curry = pq.top().second.second;
        int weight = pq.top().first;
        pq.pop();
        if(currx==N-1&&curry==N-1) break;
        if(dist[currx][curry]<weight) continue;
        for (int i = 0; i < 4; i++) {
            int nx = currx + dx[i];
            int ny = curry + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            int new_weight = weight + arr[nx][ny];
            if(new_weight<dist[nx][ny]){
                dist[nx][ny] = new_weight;
                pq.push(make_pair(new_weight, make_pair(nx, ny)));
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (true) {
        cin >> N;
        if (N == 0) break;
        for (int i = 0; i < N;i++){
            for (int j = 0; j < N;j++){
                cin >> arr[i][j];
                dist[i][j] = INF;
            }
        }
        dijkstra();
        cout << "Problem "<<num<<": "<<dist[N - 1][N - 1]<<"\n";
        num++;
    }
}