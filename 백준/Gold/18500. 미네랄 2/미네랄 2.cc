#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
char arr[101][101];
bool visited[101][101];
int R, C, N;

void bfs(int x, int y)
{
    memset(visited, false, sizeof(visited));
    vector<pair<int, int>> vct;
    queue<pair<int, int>> q;
    visited[x][y] = true;
    q.push(make_pair(x, y));
    bool floor_check = false;

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        vct.push_back(make_pair(cx, cy));
        q.pop();
        if (cx == R)
        {
            floor_check = true;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 1 || ny < 1 || nx > R || ny > C)
                continue;
            if (!visited[nx][ny] && arr[nx][ny] == 'x')
            {
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
            }
        }
    }
    // 공중에 떠있는지 아닌지 확인->떠있으면 바닥으로 내려
    if (!floor_check)
    {
        int min_diff = INT_MAX;
        for (int i = 0; i < vct.size(); i++)
        {
            arr[vct[i].first][vct[i].second] = '.';
        }
        for (int i = 0; i < vct.size(); i++)
        {
            for (int j = vct[i].first + 1; j <= R + 1; j++)
            {
                if (j == R + 1 || arr[j][vct[i].second] == 'x')
                {
                    min_diff = min(min_diff, j - vct[i].first - 1);
                    break;
                }
            }
        }
        for (int i = 0; i < vct.size(); i++)
        {
            int cx = vct[i].first;
            int cy = vct[i].second;
            arr[cx + min_diff][cy] = 'x';
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> R >> C;
    for (int i = 1; i <= R; i++)
    {
        string str;
        cin >> str;
        for (int j = 1; j <= C; j++)
        {
            arr[i][j] = str[j - 1];
        }
    }
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        int a;
        cin >> a;
        a = R - a + 1;
        if (i % 2 != 0)
        {
            for (int j = 1; j <= C; j++)
            {
                if (arr[a][j] == 'x')
                {
                    arr[a][j] = '.';
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = a + dx[k];
                        int ny = j + dy[k];
                        if (nx >= 1 && nx <= R && ny >= 1 && ny <= C && arr[nx][ny] == 'x')
                            bfs(nx, ny);
                    }

                    break;
                }
            }
        }
        else
        {
            for (int j = C; j >= 1; j--)
            {
                if (arr[a][j] == 'x')
                {
                    arr[a][j] = '.';
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = a + dx[k];
                        int ny = j + dy[k];
                        if (nx >= 1 && nx <= R && ny >= 1 && ny <= C && arr[nx][ny] == 'x')
                            bfs(nx, ny);
                    }

                    break;
                }
            }
        }
    }
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            cout << arr[i][j];
        }
        cout << "\n";
    }
}