#include<iostream>
#include<queue>
using namespace std;
int N, K;
int cnt = 0;
int visited[100001];
void bfs()
{
    queue<int> q;
    q.push(N);
    visited[N] = 1;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            int front = q.front();
            q.pop();
            if(front==K){
                return ;
            }
            int first = front - 1;
            int second = front + 1;
            int third = front * 2;
            if (first>=0&&visited[first]==0){
                q.push(first);
                visited[first] = 1;
            }
            if (second<=100000&&visited[second]==0){
                q.push(second);
                visited[second] = 1;
            }
            if (third<=100000&&visited[third]==0){
                q.push(third);
                visited[third] = 1;
            }
        }
        cnt++;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    bfs();
    cout << cnt;
}