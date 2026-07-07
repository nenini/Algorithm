#include <string>
#include <vector>
#include <queue>
using namespace std;
// 직선 도로 : 100원
// 코너 : 500원
// 경주로를 건설하는데 필요한 최소 비용

struct Point{
    int w;
    int x;
    int y;
    int dir; // 1:좌, 2: 우, 3: 하, 4:상
};

struct Compare{
    bool operator()(const Point& a, const Point& b){
        return a.w>b.w;
    };
};

int dist[25][25][4];
int dx[4]={0,0,1,-1}; // 좌, 우, 하, 상
int dy[4]={-1,1,0,0};

int dijkstra(vector<vector<int>> board){
    priority_queue<Point,vector<Point>, Compare> pq;
    pq.push({0,0,0,0});
    
    while(!pq.empty()){
        Point p=pq.top();
        pq.pop();
        
        if(p.x==board.size()-1&&p.y==board.size()-1){
            return p.w;
        }
        for(int i=0;i<4;i++){
            int nx=p.x+dx[i];
            int ny=p.y+dy[i];
            if(nx<0||ny<0||nx>=board.size()||ny>=board.size()) continue;
            if(board[nx][ny]==1) continue;

            int d=p.dir;
            int nw=p.w+100;
            
            if(p.dir != 0 &&d!=(i+1)){
                nw+=500;
            }
            
            if(dist[nx][ny][i]!=0&&dist[nx][ny][i]<=nw) continue;
            dist[nx][ny][i]=nw;
            pq.push({nw,nx,ny,i+1});
            
            
        }
    }
    return -1;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    
    return dijkstra(board);
}