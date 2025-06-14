#include <bits/stdc++.h>
using namespace std;
int parent[100001];
bool visited[100001];
int N, K;
void bfs() {
    queue<pair<int,int> > q;
    visited[N] = true;
    parent[N] = -1;
    q.push(make_pair(N, 0));
    while(!q.empty()){
        int cur = q.front().first;
        int cur_time = q.front().second;
        q.pop();
        if(cur==K){
            cout << cur_time << "\n";
            vector<int> vct;
            vct.push_back(cur);
            while (true) {
                if (parent[cur] == -1) {
                    break;
                }
                vct.push_back(parent[cur]);
                cur = parent[cur];
            }
            reverse(vct.begin(), vct.end());
            for (int i = 0; i < vct.size();i++){
                cout << vct[i] << " ";
            }
        }
        for (int i : {cur-1,cur+1,cur*2}){
            if (i >= 0 && i <= 100000 && !visited[i]) {
                q.push(make_pair(i,cur_time+1));
                parent[i] = cur;
                visited[i] = true;
            }
        } 
    }
}
int main() { 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    bfs();
}