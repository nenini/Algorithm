#include<iostream>
#include<queue>
#include<algorithm>
#define INF int(1e9)
using namespace std;
int M, N;
string input;
int arr[101][101];
int dist[101][101];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int result;
// vector<pair<int, int> > edge[10001];
void dijkstra(void){
    priority_queue<pair<pair<int,int>, int>, vector<pair<pair<int,int>, int> >, greater<pair<pair<int,int>, int> > > pq;
    pq.push(make_pair(make_pair(0, 0), 0)); //count,x,y
    dist[0][0] = 0;
    while (!pq.empty())
    {
        int curr_count = pq.top().first.first;
        int curr_x = pq.top().first.second;
        int curr_y = pq.top().second;
        pq.pop();
        if(curr_x==N-1&&curr_y==M-1){
            result = dist[N - 1][M - 1];
            break;
        }
        if(dist[curr_x][curr_y]<curr_count){
            continue;
        }
        for (int i = 0; i < 4;i++){
            int next_count;
            int next_x = curr_x + dx[i];
            int next_y = curr_y + dy[i];
            if (next_x < 0 || next_y < 0||next_x>=N||next_y>=M) continue;
            if(arr[next_x][next_y]==0){
                next_count = dist[curr_x][curr_y];
            }else{
                next_count = dist[curr_x][curr_y]+1;
            }
            if(dist[next_x][next_y]>next_count){
                dist[next_x][next_y] = next_count;
                pq.push(make_pair(make_pair(next_count, next_x), next_y));
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> M >> N;
    for (int i = 0; i < N;i++){
        cin >> input;
        for (int j = 0; j < M;j++){
            arr[i][j] = input[j] - '0';
            dist[i][j] = INF;
        }
    }
    dijkstra();
    cout << result;
}