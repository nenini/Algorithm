#include<iostream>
#include<vector>
#include<queue>
#define INF int(1e9)
using namespace std;
vector<pair<int, int > > edge[101];
int n, m, r;
int t[101];
int path[101];
int answer = 0;
int result = 0;
void dijkstra(int start)
{
    priority_queue<pair<int, int> > pq;
    path[start] = 0;
    pq.push(make_pair(0,start));
    while(!pq.empty()){
        int curr = pq.top().second;
        int weight = -pq.top().first;
        pq.pop();
        if(path[curr]<weight){
            continue;
        }
        for (int i = 0; i < edge[curr].size();i++){
            int new_curr = edge[curr][i].second;
            int new_weight = weight - edge[curr][i].first;
            if(path[new_curr]>new_weight){
                path[new_curr] = new_weight;
                pq.push(make_pair(-new_weight, new_curr));
            }
        }
    }
    for (int i = 1; i <= n;i++){
        if (path[i] <= m)
        {
            result += t[i];
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> r;
    for (int i = 1; i <= n;i++){
        cin >> t[i];
    }
    int a, b, I;
    for (int i = 0; i < r; i++)
    {
        cin >> a >> b >> I;
        //양방향 경로 삽입
        edge[a].push_back(make_pair(-I, b));
        edge[b].push_back(make_pair(-I, a));
    }
    for (int i = 1; i <= n;i++){
        for (int i = 1; i <= n;i++){
            path[i] = INF;
        }
        dijkstra(i);
        if(answer<result){
            answer = result;
        }
        result = 0;
    }
    cout << answer;
}