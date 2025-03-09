#include<iostream>
#include<vector>
#include<queue>
#define INF int(1e9)
using namespace std;
int N, M, X;
vector<pair<int, int> > edge[10001];
int dist[1001];
int result;
int answer=0;

void dijkstra(int start,int end){
    result = 0;
    for (int i = 1; i <= N;i++){
        dist[i] = INF;
    }
        priority_queue<pair<int, int> > pq;
    dist[start] = 0;
    pq.push(make_pair(0, start));
    while(!pq.empty()){
        int curr = pq.top().second;
        int weight = -pq.top().first;
        pq.pop();
        if(curr==end){
            result = dist[curr];
            break;
        }
        if(dist[curr]<weight){
            continue;
        }
        for (int i = 0; i < edge[curr].size();i++){
            int new_curr = edge[curr][i].second;
            int new_weight = weight - edge[curr][i].first;
            if(dist[new_curr]>new_weight){
                dist[new_curr] = new_weight;
                pq.push(make_pair(-new_weight, new_curr));
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> X;
    int u, v, w;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v >> w;
        edge[u].push_back(make_pair(-w, v));
    }
    for (int i = 1; i < N + 1;i++){
        int go_back=0;
        dijkstra(i, X);
        go_back += result;
        dijkstra(X, i);
        go_back += result;
        if(answer<go_back){
            answer = go_back;
        }
    }
    cout << answer;
}