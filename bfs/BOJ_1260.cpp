#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N, M, V;
bool visited[1001];
vector<int> edge[10001];
vector<int> dfs_result;
vector<int> bfs_result;
void dfs(int start)
{
    visited[start] = true;
    dfs_result.push_back(start);
    for (int i = 0; i < edge[start].size(); i++)
    {
        if(!visited[edge[start][i]]){
            dfs(edge[start][i]);
        }
    }
}
void bfs(int start){
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while(!q.empty()){
        int num = q.front();
        q.pop();
        bfs_result.push_back(num);
        for (int i = 0; i < edge[num].size(); i++)
        {
            if(!visited[edge[num][i]]){
                q.push(edge[num][i]);
                visited[edge[num][i]] = true;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> V;
    int u, v;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for (int i = 1; i <= N;i++){
        sort(edge[i].begin(), edge[i].end());
    }
    dfs(V);
    for (int i = 0; i <=N;i++){
        visited[i] = false;
    }
    bfs(V);
    for (int i = 0; i < dfs_result.size();i++){
        if(i<dfs_result.size()-1){
            cout << dfs_result[i]<<" ";
        }else
        cout << dfs_result[i];
    }
    cout << "\n";
    for (int i = 0; i < bfs_result.size();i++){
        if(i<bfs_result.size()-1){
            cout << bfs_result[i]<<" ";
        }else
        cout << bfs_result[i];
    }
}