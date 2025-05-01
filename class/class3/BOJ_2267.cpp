#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int N;
char arr[26][26];
int visited[26][26];
int group=0;
int house = 0;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

struct cmp{
    bool operator()(int a, int b){
        if(a>b)
            return true;
        else
            return false;
    }
};
priority_queue<int,vector<int>, cmp> q;


void dfs(int x, int y){
    visited[x][y] = 1;
    house++;
    for (int i = 0; i < 4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<0||ny<0||nx>=N||ny>=N){
            continue;
        }
        if(visited[nx][ny]==0&&arr[nx][ny]=='1'){
            dfs(nx, ny);
        }
    }
}
int main()
{
    cin >> N;
    for (int i = 0; i < N;i++){
        cin >> arr[i];
    }
    for (int i = 0; i < N;i++){
        for (int j = 0; j < N;j++){
            if(visited[i][j]==0&&arr[i][j]=='1'){
                dfs(i, j);
                q.push(house);
                house = 0;
                group++;
            }
        }
    }
    cout << group << "\n";
    for (int i = 0; i < group; i++)
    {
        cout << q.top() << "\n";
        q.pop();
    }
}