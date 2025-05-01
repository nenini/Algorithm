#include<iostream>
#include<string.h>
using namespace std;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int N;
char arr[101][101];
int visited[101][101];
int cnt=0;

void dfs(int x, int y)
{
    visited[x][y] = 1;
    for (int i = 0; i < 4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<0||ny<0||nx>=N||ny>=N){
            continue;
        }
        if(visited[nx][ny]==0&&arr[x][y]==arr[nx][ny]){
            dfs(nx, ny);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N;i++){
        cin >> arr[i];
    }
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < N;i++){
        for (int j = 0; j < N;j++){
            if(visited[i][j]==0){
                dfs(i,j);
                cnt++;
            }
        }
    }
    cout << cnt << " ";
    for (int i = 0; i < N;i++){
        for (int j = 0; j < N;j++){
            if(arr[i][j]=='G'){
                arr[i][j] = 'R';
            }
        }
    }
    memset(visited, 0, sizeof(visited));
    cnt=0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N;j++){
            if(visited[i][j]==0){
                dfs(i,j);
                cnt++;
            }
        }
    }
    cout << cnt <<"\n";

}