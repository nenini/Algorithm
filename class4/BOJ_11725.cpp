#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N;
vector<int> edge[100001];
int arr[100001];
bool visited[100001];
void bfs()
{
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while(!q.empty()){
        int num = q.front();
        q.pop();
        for (int i = 0; i < edge[num].size();i++){
            if(!visited[edge[num][i]]){
                arr[edge[num][i]] = num;
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
    cin >> N;
    int u, v;
    for (int i = 0; i < N-1; i++)
    {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    bfs();
    for (int i = 2; i <=N ; i++)
    {
        cout << arr[i] << "\n";
    }
}