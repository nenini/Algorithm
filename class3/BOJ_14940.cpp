#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n, m;
int arr[1001][1001];
int result[1001][1001];
bool visited[1001][1001];
int xx[4] = {0, 0, 1, -1};
int yy[4] = {1, -1, 0, 0};
void bfs(int x, int y)
{
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    visited[x][y] = 1;
    result[x][y] = 0;
    while (!q.empty())
    {
        int frontx = q.front().first;
        int fronty = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int dx = frontx + xx[i];
            int dy = fronty + yy[i];
            if(dx>=0&&dy>=0&&dx<n&&dy<m&&visited[dx][dy]==0&&arr[dx][dy]!=0){
                q.push(make_pair(dx, dy));
                visited[dx][dy] = 1;
                result[dx][dy] = result[frontx][fronty] + 1;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int x, y;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m;j++){
            cin >> arr[i][j];
            if(arr[i][j]==2){
                x = i;
                y = j;
            }
        }
    }
    bfs(x, y);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m;j++){
            if (arr[i][j] == 0){
                cout << 0;
            }
            else if (result[i][j] == 0 && arr[i][j] == 1)
            {
                cout << -1;
            }
            else{
                cout << result[i][j];
            }
            if(j<m-1)
                cout << " ";
        }
        cout << "\n";
    }
}