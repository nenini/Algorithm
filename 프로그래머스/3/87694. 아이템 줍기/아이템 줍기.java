import java.util.*;
class Solution {
    public static int[] dx={0,0,1,-1};
    public static int[] dy={-1,1,0,0};
    
    public int solution(int[][] rectangle, int characterX, int characterY, int itemX, int itemY) {
        int answer = 0;
        int size=rectangle.length;
        boolean[][] arr=new boolean[101][101];
        
        for(int i=0;i<size;i++){
            int x1=2*rectangle[i][0];
            int y1=2*rectangle[i][1];
            int x2=2*rectangle[i][2];
            int y2=2*rectangle[i][3];
            for(int r=x1;r<=x2;r++){
                for(int c=y1;c<=y2;c++){
                    arr[r][c]=true;
                }
            }
        }
        
        for(int i=0;i<size;i++){
            int x1=2*rectangle[i][0];
            int y1=2*rectangle[i][1];
            int x2=2*rectangle[i][2];
            int y2=2*rectangle[i][3];
            
            for(int r=x1+1;r<x2;r++){
                for(int c=y1+1;c<y2;c++){
                    arr[r][c]=false;
                }
            }
        }
        
        Queue<Position> q=new ArrayDeque<>();
        q.offer(new Position(characterX*2,characterY*2,0));
        while(!q.isEmpty()){
            Position cur=q.poll();
            if(cur.x==itemX*2 &&cur.y==itemY*2) return cur.dist/2;
            for(int i=0;i<4;i++){
                int nx=cur.x+dx[i];
                int ny=cur.y+dy[i];
                if(nx<1||ny<1||nx>100||ny>100) continue;
                if(!arr[nx][ny])   continue;
                q.offer(new Position(nx,ny,cur.dist+1));
                arr[nx][ny]=false;
            }
        }
        
        
        
        return answer;
    }
}

class Position{
    int x;
    int y;
    int dist;
    Position(int x,int y,int dist){
        this.x=x;
        this.y=y;
        this.dist=dist;
    }
}