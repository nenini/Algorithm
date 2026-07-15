import java.util.*;
class Solution {
    static int[] dx={0,0,1,-1};
    static int[] dy={-1,1,0,0};
    
    public int solution(int[][] board, int[] aloc, int[] bloc) {
        int answer = -1;
        Pair p=dfs(board,aloc,bloc);
        
        return p.count;
    }
    
    public Pair dfs(int[][] board, int[] loc1, int[] loc2){
        boolean check=false;
        int count=0;
        int winCount=Integer.MAX_VALUE;
        int loseCount=Integer.MIN_VALUE;
        
        if (board[loc1[0]][loc1[1]] == 0) {
            return new Pair(false, 0);
        }

        for(int i=0;i<4;i++){
            int nx=loc1[0]+dx[i];
            int ny=loc1[1]+dy[i];
            
            if(nx<0||ny<0||nx>=board.length||ny>=board[0].length||board[nx][ny]==0) continue;
            check=true;
            board[loc1[0]][loc1[1]]=0;
            Pair next=dfs(board,loc2,new int[]{nx,ny});
            board[loc1[0]][loc1[1]]=1;
            
            count=next.count+1;
            
            if(next.win){
                // 상대방이 이기고 내가 지는 경우
                loseCount=Math.max(loseCount,count);
            }else{
                // 상대방이 지고 내가 이기는 경우
                loseCount=Math.max(loseCount,count);
                 winCount=Math.min(winCount,count);

            }
            
            
        }
        if(!check){
            return new Pair(false,0);
        }
        
        if(winCount!=Integer.MAX_VALUE) return new Pair(true,winCount);
        
        return new Pair(false,loseCount);
        
    }
}

class Pair{
    boolean win;
    int count;
    
    Pair(boolean win, int count){
        this.win=win;
        this.count=count;
    }
    
    
}