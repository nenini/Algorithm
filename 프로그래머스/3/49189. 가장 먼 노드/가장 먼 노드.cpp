#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> e[20001];
int max_depth=0;
int depth[20001];

void bfs(){
    queue<int> q;
    depth[1]=1;
    q.push(1);
    
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        
        max_depth=max(max_depth,depth[cur]);
        for(int i=0;i<e[cur].size();i++){
            int next=e[cur][i];
            if(depth[next]!=0) continue;
            q.push(next);
            depth[next]=depth[cur]+1;
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for(int i=0;i<edge.size();i++){
        int a=edge[i][0];
        int b=edge[i][1];
        e[a].push_back(b);
        e[b].push_back(a);
    }
    
    bfs();
    for(int i=1;i<=n;i++){
        if(depth[i]==max_depth) answer++;
    }
    
    return answer;
}