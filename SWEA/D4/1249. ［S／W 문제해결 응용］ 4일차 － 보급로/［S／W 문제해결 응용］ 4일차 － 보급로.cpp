#include <bits/stdc++.h>
using namespace std;
int T;
int arr[100][100];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
int dist[100][100];
int N;
void dijkstra() {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push(make_pair(0, make_pair(0, 0)));
    while (!pq.empty()) {
        int cx = pq.top().second.first;
        int cy = pq.top().second.second;
        int cw = pq.top().first;
        if(cx==N-1&&cy==N-1){
            return ;
        }
        pq.pop();
        if (dist[cx][cy] < cw) continue;
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            int nw=cw+arr[nx][ny];
            if(nw<dist[nx][ny]){
                pq.push(make_pair(nw,make_pair(nx,ny)));
                dist[nx][ny]=nw;
            }
        }
    }
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    for (int test = 1; test <= T; test++) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            string str;
            cin >> str;
            for (int j = 0; j < N; j++) {
                arr[i][j] = str[j] - '0';
                dist[i][j]=INT_MAX;
            }
        }
        dijkstra();
        cout << "#" << test << " " << dist[N-1][N-1] << "\n";
    }
}