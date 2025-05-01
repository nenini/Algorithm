#include <bits/stdc++.h>
#define INF (int)1e9
using namespace std;
int V, E, K;
int result[20001];
vector<pair<int, int> > vct[300001];
void dijstra(int start) {
    priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    result[start] = 0;
    pq.push(make_pair(0,start));//weight,u
    while(!pq.empty()){
        int curr = pq.top().second;
        int weight = pq.top().first;
        pq.pop();
        if (result[curr] < weight) continue;
        for (int i = 0; i < vct[curr].size();i++){
            int new_curr = vct[curr][i].second;
            int new_weight = weight +vct[curr][i].first;
            if(new_weight<result[new_curr]){
                result[new_curr] = new_weight;
                pq.push(make_pair(new_weight, new_curr));
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> V >> E >> K;
    for (int i = 0; i <= V; i++) {
        result[i] = INF;
    }
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        vct[u].push_back(make_pair(w, v));
    }
    dijstra(K);
    for (int i = 1; i <= V; i++) {
        if(result[i]==INF){
            cout << "INF" << "\n";
        }else
        cout << result[i] << "\n";
    }
}

// //다익스크라 코드 다시 공부
// #include<iostream>
// #include<vector>
// #include<queue>
// using namespace std;
// int V, E;
// int K;
// vector<pair<int, int> > vct[300001];
// int result[20001];
// void dijkstra(int start){
//     result[start] = 0;
//     priority_queue<pair<int, int> > pq;
//     pq.push(make_pair(0, start));
//     while(!pq.empty()){
//         int curr = pq.top().second;//다음 경로를 현재 경로로
//         int weight = -pq.top().first;
//         pq.pop();
//         if(result[curr]<weight){
//             continue;
//         }
//         for (int i = 0; i < vct[curr].size();i++){
//             int new_v = vct[curr][i].second;
//             int new_weight = weight + -vct[curr][i].first;
//             if(result[new_v]>new_weight){
//                 result[new_v] = new_weight;
//                 pq.push(make_pair(-new_weight, new_v));
//             }
//         }
//     }
// }
// int main(void)
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> V >> E;
//     cin >> K;
//     int u, v, w;
//     for (int i = 0; i < E; i++)
//     {
//         cin >> u >> v >> w;
//         vct[u].push_back(make_pair(-w,v));
//     }
//     for (int i = 1; i <= V;i++){
//         result[i] = int(1e9);
//     }
//     dijkstra(K);
//     for (int i = 1; i <= V;i++){
//         if(result[i]==int(1e9)){
//             cout << "INF" << "\n";
//         }else{
//             cout << result[i]<<"\n";
//         }
//     }
// }