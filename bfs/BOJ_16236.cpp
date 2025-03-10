#include<iostream>
#include<queue>
using namespace std;
int N;
int arr[21][21];
int visited[21][21];
int curx, cury;
int dist;
int shark_size=2;
int eat = 0;
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0,-1,1,0};
int bfs(){
    for (int i = 0; i < N;i++){
            for (int j = 0; j < N;j++){
                visited[i][j] = 0;
            }
        }
    dist = 0;
    queue<pair<int, int> > q;
    priority_queue<pair<int, int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    q.push(make_pair(curx, cury));
    visited[curx][cury] = 1;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (visited[x][y] == dist)
			break;
        for (int i = 0; i < 4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0||ny<0||nx>=N||ny>=N) continue;
            if((arr[nx][ny]==0||arr[nx][ny]==shark_size)&&!visited[nx][ny]){
                q.push(make_pair(nx, ny));
                visited[nx][ny] = visited[x][y] + 1;
            }else if(arr[nx][ny]<shark_size&&!visited[nx][ny]){
                if(!dist)
                    eat++;
                visited[nx][ny] = visited[x][y] + 1;
                dist = visited[nx][ny];
                pq.push(make_pair(nx, ny));
            }
        }
    }
    if(pq.empty()){
        return 0; //먹은게 없음
    }
    curx = pq.top().first;
    cury = pq.top().second;
    
    if(eat==shark_size){
        shark_size++;
        eat = 0;
    }
    arr[curx][cury] = 0;
    return visited[curx][cury]-1; //처음에 1부터 시작
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N;i++){
        for (int j = 0; j < N;j++){
            cin >> arr[i][j];
            if(arr[i][j]==9){
                curx = i;
                cury = j;
                arr[i][j] = 0;
            }
        }
    }
    int answer = 0;
    while (1)
    {
        int bfs_result = bfs();
        if(bfs_result==0){
            break;
        }
        answer += bfs_result;
    }
    cout << answer;
}