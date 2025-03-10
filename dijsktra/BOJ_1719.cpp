#include<iostream>
#include<vector>
#include<queue>
#define INF 1e9
using namespace std;
int n, m;
vector<pair<int, int> > edge[10001];
int path[201];
int cost[201];
void dijkstra(int start)
{
    priority_queue<pair<int, int> > pq;
    cost[start] = 0;
    pq.push(make_pair(0, start));
    while (!pq.empty())
    {
        int curr = pq.top().second;
        int weight = -pq.top().first;
        pq.pop();
        if(cost[curr]<weight)
            continue;
        for (int i = 0; i < edge[curr].size();i++){
            int new_curr = edge[curr][i].second;
            int new_weight = weight - edge[curr][i].first;
            if(cost[new_curr]>new_weight){
                cost[new_curr] = new_weight;
                path[new_curr] = curr;
                pq.push(make_pair(-new_weight,new_curr));
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int u, v, w;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        edge[u].push_back(make_pair(-w, v));
        edge[v].push_back(make_pair(-w, u));
    }
    for (int i = 1;i<=n;i++){
        for (int j = 0; j <= n;j++){
            cost[j] = INF;
        }
        dijkstra(i);
        for (int k = 1; k <= n;k++){
            if(i==k){
                cout << "-";
            }else{
                int end=k;
                while (1)
                {
                    if(path[end]==i){
                        break;
                    }
                    end = path[end];
                }
                cout << end;
            }
            if (k < n){
                cout << " ";
            }
        }
        cout << "\n";
    }
}