import java.util.*;
class Solution {
    public int[] dx={0,0,1,-1};
    public int[] dy={-1,1,0,0};
    
    public int solution(int[][] land) {
        int answer = 0;
        int w=land[0].length;
        int h=land.length;
        
        boolean[][] visited=new boolean[h][w];
        int[] colSum=new int[w];
        for(int col=0;col<w;col++){
            for(int row=0;row<h;row++){
                if(visited[row][col]||land[row][col]==0) continue;
                bfs(row,col,visited,w,h,land,colSum);
            }
            answer=Math.max(answer,colSum[col]);
        }
        
        return answer;
    }
    
    public void bfs(int x,int y,boolean[][] visited,int w,int h,int[][] land,int[] colSum){
        int sum=0;
        Queue<int[]> q=new ArrayDeque<>();
        q.offer(new int[]{x,y});
        visited[x][y]=true;
        
        sum=1;
        Set<Integer> set=new HashSet<>();
        
        while(!q.isEmpty()){
            int[] cur=q.poll();
            set.add(cur[1]);
            for(int i=0;i<4;i++){
                int nx=cur[0]+dx[i];
                int ny=cur[1]+dy[i];
                
                if(nx<0||ny<0||nx>=h||ny>=w) continue;
                if(visited[nx][ny]||land[nx][ny]==0) continue;
                
                visited[nx][ny]=true;
                q.offer(new int[]{nx,ny});
                sum++;
            }
        }
        
        for(int s:set){
            colSum[s]+=sum;
        }
        
        
    }
}