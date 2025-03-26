#include<iostream>
#include<string>
#include<queue>
#include<vector>
using namespace std;
// string str[5];
char arr[5][5];
int result = 0;
bool visited[5][5];
bool checked[5][5];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
bool isS()
{
    int cnt = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5;j++){
            if(visited[i][j]){
                if(arr[i][j]=='S'){
                    cnt++;
                }
            }
        }
    }
    if(cnt>=4){
        return true;
    }else{
        return false;
    }
}
bool bfs(){
    int flag = 0;
    for (int i = 0;i<5;i++){
        for (int j = 0;j<5;j++){
            checked[i][j] = false;
        }
    }
    queue<pair<int, int> > q;
    for (int i = 0;i<5;i++){
        for (int j = 0;j<5;j++){
            if(visited[i][j]){
                q.push(make_pair(i, j));
                checked[i][j] = true;
                flag = 1;
                break;
            }
        }
        if(flag==1){
            break;
        }
    }
    int princess=1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(princess==7){
            return true;
        }
        for (int i = 0; i < 4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0||ny<0||nx>=5||ny>=5) continue;
            if(checked[nx][ny]||!visited[nx][ny]) continue;
            q.push(make_pair(nx, ny));
            princess++;
            checked[nx][ny] = true;
        }
    }
    if(princess==7){
        return true;
    }
    return false;
}
void dfs(int num, int index1,int index2){
    if(num==7){
        if(isS()&&bfs()){
            result++;
            return;
        }
    }
    for (int i = index1;i<5;i++){
        for (int j = (i == index1 ? index2 : 0);j<5;j++){
            if(!visited[i][j]){
                visited[i][j] = true;
                dfs(num + 1, i,j);
                visited[i][j] = false;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    dfs(0, 0,0);
    cout << result;
}