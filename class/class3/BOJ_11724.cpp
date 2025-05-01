//dfs,bfs 사용->연결노드 개수 찾기
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> v[1001];
int visited[1001];
int cnt = 0;
void dfs(int n)
{
    visited[n] = 1;
    for (int i = 0; i < v[n].size();i++){
        if(visited[v[n][i]]==0){
            dfs(v[n][i]);
        }
    }
}
void bfs(int n){
    queue<int> q;
    visited[n] = 1;
    q.push(n);
    while(!q.empty()){
        int start = q.front();
        q.pop();
        for (int i = 0; i < v[start].size();i++){
            if(visited[v[start][i]]==0){
                q.push(v[start][i]);
                visited[v[start][i]] = 1;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M;i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= N;i++){
        if(visited[i]==0){
            // dfs(i);
            bfs(i);
            cnt++;
        }
    }
    cout << cnt;
}