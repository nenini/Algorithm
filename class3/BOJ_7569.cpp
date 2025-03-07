#include<iostream>
#include<queue>
using namespace std;
int M, N, H;
bool check = true;
queue<pair<pair<int, int>, int> > q;
int result=0;
int arr[101][101][101];
int dx[6] = {0, 0, 0, 0, 1, -1};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {1, -1, 0, 0, 0, 0};

void bfs()
{
    while(!q.empty()){
        int first = q.front().first.first;
        int second = q.front().first.second;
        int third = q.front().second;
        for (int i = 0; i < 6;i++){
            int new_first= first + dx[i];
            int new_second =second+ dy[i];
            int new_third = third + dz[i];
            if(new_first<H&&new_second<N&&new_third<M&&new_first>=0&&new_second>=0&&new_third>=0&&arr[new_first][new_second][new_third]==0){
                arr[new_first][new_second][new_third] = arr[first][second][third] + 1;
                q.push(make_pair(make_pair(new_first, new_second), new_third));            
            }
        }
        q.pop();
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> M >> N >> H;
    for (int i = 0; i < H;i++){
        for (int j = 0; j < N;j++){
            for (int k = 0; k < M;k++){
                cin >> arr[i][j][k];
                if(arr[i][j][k]==1){
                    q.push(make_pair(make_pair(i, j), k));
                }
                if(arr[i][j][k]==0){
                    check = false;
                }
            }
        }
    }
    if(check==true){
        cout << 0;
        return 0;
    }
    bfs();
    for (int i = 0; i < H;i++){
        for (int j = 0; j < N;j++){
            for (int k = 0; k < M;k++){
                if(arr[i][j][k]==0){
                    cout << -1;
                    return 0;
                }
                if(result<arr[i][j][k]){
                    result = arr[i][j][k];
                    
                }
            }
        }
    }
    cout << result-1;
}