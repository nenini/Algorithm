#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, M;
int start_city, end_city;
vector<pair<int, int> > edge[100001];
int result[1001];
priority_queue<pair<int, int> > pq;
void dijstra(int start)
{
    result[start] = 0;
    pq.push(make_pair(0, start));//시작 위치 추가
    while(!pq.empty()){
        int curr = pq.top().second;
        int weight = -pq.top().first;
        pq.pop();
        if(result[curr]<weight)
            continue;
        for (int i = 0; i < edge[curr].size();i++){
            int new_curr = edge[curr][i].second;
            int new_weight = weight-edge[curr][i].first;
            if(result[new_curr]>new_weight){
                result[new_curr] = new_weight;
                pq.push(make_pair(-new_weight, new_curr));
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    int u, v, w;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v >> w;
        edge[u].push_back(make_pair(-w, v));
    }
    for (int i = 1; i < N+1;i++){
        result[i] = int(1e9);
    }
    cin >> start_city >> end_city;
    dijstra(start_city);
    cout << result[end_city];
}