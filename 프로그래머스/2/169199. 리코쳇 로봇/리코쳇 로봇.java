import java.util.*;
class Solution {
    public int[] dx={0,0,1,-1};
    public int[] dy={-1,1,0,0};
    
    public int solution(String[] board) {
        int answer = 0;
        
        for(int i=0;i<board.length;i++){
            for(int j=0;j<board[i].length();j++){
                char cur=board[i].charAt(j);
                if(cur=='R'){
                    return bfs(i,j,board);
                }
                
            }
        }
        
        return answer;
    }
    
    public int bfs(int x,int y,String[] board){
        int h=board.length;
        int w=board[0].length();
        
        int[][] visited=new int[h][w];
        for (int i = 0; i < h; i++) {
            Arrays.fill(visited[i], -1);
        }
        Queue<int[]> q=new ArrayDeque<>();
        visited[x][y]=0;
        q.offer(new int[]{x,y});
        
        while(!q.isEmpty()){
            int[] cur=q.poll();
            if(board[cur[0]].charAt(cur[1])=='G') {
                return visited[cur[0]][cur[1]];
            }
            for(int i=0;i<4;i++){
                int[] next=move(board,cur,i,h,w);
                if(visited[next[0]][next[1]]!=-1) continue;
                q.offer(next);
                visited[next[0]][next[1]]=visited[cur[0]][cur[1]]+1;
            }
        }
        
        return -1;
        
    }
    
    public int[] move(String[] board,int[] cur,int direct,int h,int w){
        int x=cur[0];
        int y=cur[1];
        while(true){
            int nx=x+dx[direct];
            int ny=y+dy[direct];
            if(nx<0||ny<0||nx>=h||ny>=w) break;
            if(board[nx].charAt(ny)=='D') break;
            
            x=nx;
            y=ny;
        }
        return new int[]{x,y};
    }
}