#include<iostream>
#include<queue>
using namespace std;
int n, m;
int arr[101][101];
int visited[101][101];
int result_time=0;
int cnt=0;
int result_cnt;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int bfs()
{
    cnt = 0;
    queue<pair<int, int> > q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m;j++){
            visited[i][j] = 0;
        }
    }
    visited[0][0] = 1;
    q.push(make_pair(0, 0));
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0||ny<0||nx>=n||ny>=m||visited[nx][ny]) continue;
            if(arr[nx][ny]==0){
                visited[nx][ny] = 1;
                q.push(make_pair(nx, ny));
            }else{ //치즈일때
                cnt++;
                arr[nx][ny]=0;
                visited[nx][ny] = 1;
            }
        }
    }
    if(cnt==0){
        cout << result_time << "\n"
             << result_cnt;
        return cnt;
    }else{
        result_cnt = cnt;
        result_time++;
        return cnt;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            cin >> arr[i][j];
        }
    }
    while(1){
        if(!bfs())
            break;
    }
}
