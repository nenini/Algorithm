#include <bits/stdc++.h>

using namespace std;

bool visited[100][100];
int dx[4]={0,0,1,-1};
int dy[4]={-1,1,0,0};
int size_x;
int size_y;

int bfs(int x,int y,vector<string> maps){
    queue<pair<int,int> > q;
    q.push(make_pair(x,y));
    visited[x][y]=true;
    int sum = (maps[x][y]-'0');
    while(!q.empty()){
        int cx=q.front().first;
        int cy=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=dx[i]+cx;
            int ny=dy[i]+cy;
            if(nx<0||ny<0||nx>=size_x||ny>=size_y) continue;
            if(!visited[nx][ny]&maps[nx][ny]!='X'){
                q.push(make_pair(nx,ny));
                sum+=(maps[nx][ny]-'0');
                visited[nx][ny]=true;
            }
            
        }
    }
    return sum;
}
vector<int> solution(vector<string> maps) {
    
    vector<int> answer;
    size_x=maps.size();
    size_y=maps[0].length();
    
    for(int i=0;i<size_x;i++){
        for(int j=0;j<size_y;j++){
            int sum=0;
            if(maps[i][j]!='X'&&!visited[i][j]) sum=bfs(i,j,maps);
            if(sum!=0) answer.push_back(sum);
        }
    }
    
    if(answer.empty()) return {-1};
    sort(answer.begin(),answer.end());
    
    
    return answer;
}