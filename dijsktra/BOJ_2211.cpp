#include<iostream>
#include<vector>
#include<queue>
#define INF 1e9
using namespace std;
int N, M;
vector<pair<int, int> > edge[1001];
int path[1001];
int cost[1001];
void dijkstra(int start)
{
    priority_queue<pair<int, int> > pq;
    cost[start] = 0;
    pq.push(make_pair(0, start));
    while(!pq.empty()){
        int curr = pq.top().second;
        int weigt = -pq.top().first;
        pq.pop();
        if(cost[curr]<weigt) continue;
        for (int i = 0; i < edge[curr].size();i++){
            int new_curr = edge[curr][i].second;
            int new_weight = weigt - edge[curr][i].first;
            if(cost[new_curr]>new_weight){
                cost[new_curr] = new_weight;
                path[new_curr] = curr;
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
    int A, B, C;
    for (int i = 0; i < M;i++){
        cin >> A >> B >> C;
        edge[A].push_back(make_pair(-C, B));
        edge[B].push_back(make_pair(-C, A));
    }
    for (int i = 1; i <= N;i++){
        cost[i] = INF;
    }
    dijkstra(1);
    cout << N - 1 << "\n";
    for (int i = 2; i <= N ;i++){
        cout << path[i] <<" "<< i<<"\n";
    }
}