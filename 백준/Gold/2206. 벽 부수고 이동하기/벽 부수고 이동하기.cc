#include<iostream>
#include<queue>
#include<string>

using namespace std;
int N, M;
int result =int(1e9);
int wall_check = 0;
bool possible = false;
int arr[1001][1001][2]; //원본
// int temp[1001][1001]; //벽 없애는 복사본
// int visited[1001][1001];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int bfs(){ 
    queue<pair<pair<int,int>, int> > q;
    q.push(make_pair(make_pair(0, 0),0));
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int wall = q.front().second;
        q.pop();
        if(x==N-1&&y==M-1){
            return arr[x][y][wall] + 1;
        }
        for (int i = 0; i < 4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0||ny<0||nx>=N||ny>=M) continue;
            if(arr[nx][ny][0]==1){
                if(!wall){
                    arr[nx][ny][wall+1] = arr[x][y][wall] + 1;
                    q.push(make_pair(make_pair(nx, ny), 1));
                }

            }else if(arr[nx][ny][0]==0){
                if(wall==1&&arr[nx][ny][wall]){
                    continue;
                }
                arr[nx][ny][wall] = arr[x][y][wall] + 1;
                q.push(make_pair(make_pair(nx, ny), wall));
            }
        }
    }
    return -1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    string s;
    
    for (int i = 0; i < N;i++){
        cin >> s;
        for (int j = 0; j < M;j++){
            arr[i][j][0] = s[j]-'0';
        }
    }
    cout<<bfs();
    
}