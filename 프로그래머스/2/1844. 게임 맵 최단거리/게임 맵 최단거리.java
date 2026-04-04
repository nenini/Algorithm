import java.util.*;

class Solution {
    int[] dx={0,0,1,-1};
    int[] dy={-1,1,0,0};
    int answer = Integer.MAX_VALUE;
    
    public int solution(int[][] maps) {
        Point end=new Point(maps.length-1,maps[0].length-1,0);
        Point start=new Point(0,0,1);
        
        bfs(start,end,maps.length,maps[0].length,maps);
        if(answer==Integer.MAX_VALUE) return -1;
        return answer;
    }
    
    public void bfs(Point start,Point end,int n,int m,int[][] maps){
        boolean[][] visited=new boolean[n][m];
        Queue<Point> q=new ArrayDeque<>();
        
        q.offer(start);
        visited[start.x][start.y]=true;
        
        while(!q.isEmpty()){
            Point cur=q.poll();
            if(cur.x==end.x&&cur.y==end.y){
                answer=Math.min(cur.w,answer);
                break;
            }
            for(int i=0;i<4;i++){
                int nx=cur.x+dx[i];
                int ny=cur.y+dy[i];
                if(nx<0||ny<0||nx>=n||ny>=m) continue;
                if(maps[nx][ny]==0||visited[nx][ny]) continue;
                q.offer(new Point(nx,ny,cur.w+1));
                visited[nx][ny]=true;
            }
        }
        
    }
}
class Point{
    int x;
    int y;
    int w;
    public Point(int x,int y,int w){
        this.x=x;
        this.y=y;
        this.w=w;
    }
}