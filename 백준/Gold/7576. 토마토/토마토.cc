#include<iostream>
#include<queue>
using namespace std;

int box[1000][1000];
queue <pair<int, int> > q;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int min_day=0;
int n,m;
void bfs(){
    int x,y;
    while(!q.empty()){
        x=q.front().first;
        y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int ax=x+dx[i];
            int ay=y+dy[i];
            if(ax>=0 && ay>=0&& ax<m && ay<n){
                if(box[ax][ay]==0){
                    box[ax][ay]=box[x][y]+1;
                    q.push(pair<int, int>(ax, ay));
                }
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        for(int j=0; j<n;j++){
            cin>>box[i][j];
            if(box[i][j]==1){
                q.push(pair<int, int>(i, j));//1이면 저장
            }
        }
    }
    bfs();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(box[i][j]==0){
                cout<<-1;
                return 0;
            }
            if(min_day<box[i][j]){
                min_day=box[i][j];
            }
        }
    }
    cout<<min_day-1;
}