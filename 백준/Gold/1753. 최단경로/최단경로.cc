#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int V, E;
int K;
vector<pair<int, int> > vct[300001];
int result[20001];
void dijkstra(int start){
    result[start] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, start));
    while(!pq.empty()){
        int curr = pq.top().second;//다음 경로를 현재 경로로
        int weight = -pq.top().first;
        pq.pop();
        if(result[curr]<weight){
            continue;
        }
        for (int i = 0; i < vct[curr].size();i++){
            int new_v = vct[curr][i].second;
            int new_weight = weight + -vct[curr][i].first;
            if(result[new_v]>new_weight){
                result[new_v] = new_weight;
                pq.push(make_pair(-new_weight, new_v));
            }
        }
    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> V >> E;
    cin >> K;
    int u, v, w;
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        vct[u].push_back(make_pair(-w,v));
    }
    for (int i = 1; i <= V;i++){
        result[i] = int(1e9);
    }
    dijkstra(K);
    for (int i = 1; i <= V;i++){
        if(result[i]==int(1e9)){
            cout << "INF" << "\n";
        }else{
            cout << result[i]<<"\n";
        }
    }
}