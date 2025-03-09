#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define INF int(1e9)
using namespace std;
int n, m;
int start_city, end_city;
vector<pair<int, int> > edge[100001];
int result[1001];
int AB[1001];
vector<int> path;

void dijkstra(int start, int end){
    priority_queue<pair<int, int> > pq;
    result[start] = 0;
    pq.push(make_pair(0, start));
    while(!pq.empty()){
        int curr = pq.top().second;
        int weight = -pq.top().first;
        pq.pop();
        if(curr==end){
            break;
        }
        if(result[curr]<weight) continue;
        for (int i = 0; i < edge[curr].size();i++){
            int new_curr = edge[curr][i].second;
            int new_weight = weight - edge[curr][i].first;
            if(result[new_curr]>new_weight){
                result[new_curr] = new_weight;
                AB[new_curr] = curr;
                pq.push(make_pair(-new_weight, new_curr));
            }
        }
    }
    int a = end;
    while(a!=start){
        path.push_back(a);
        a = AB[a];
    }
    path.push_back(a);
    reverse(path.begin(), path.end());
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int u, v, w;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        edge[u].push_back(make_pair(-w, v));
    }
    for (int i = 1; i <= n;i++){
        result[i] = INF;
    }
    cin >> start_city >> end_city;
    dijkstra(start_city, end_city);
    cout << result[end_city] << "\n";
    cout << path.size()<<"\n";
    for (int i = 0; i < path.size();i++){
        if(i+1==path.size()){
            cout << path[i];
        }else{
            cout << path[i] << " ";
        }
    }
}