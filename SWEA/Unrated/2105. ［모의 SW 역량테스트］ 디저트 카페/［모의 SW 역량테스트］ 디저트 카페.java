import java.io.*;
import java.util.*;

public class Solution {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st ;
    static StringBuilder sb=new StringBuilder();

    static int TC;
    static int N;
    static int[][] dessert;
    static int startX,startY,sum;
    static boolean[][] visited;
    static boolean[] eaten;
    static int[] dx={1,1,-1,-1};
    static int[] dy={1,-1,-1,1};

    public static void main(String[] args) throws Exception {
        TC = Integer.parseInt(br.readLine().trim());
        for(int testcase=1;testcase<=TC;testcase++) {
            sb.append("#").append(testcase).append(" ");
            input();
            for(int i=0;i<N;i++) {
                for(int j=0;j<N;j++) {
                    startX=i;
                    startY=j;
                    eaten[dessert[i][j]]=true;
                    dfs(0,i,j,0);
                    eaten[dessert[i][j]]=false;
                }
            }
            if(sum==0){
                sb.append(-1);
            }else{
                sb.append(sum);
            }
            sb.append("\n");
        }
        System.out.println(sb);

    }

    public static void dfs(int count,int x,int y,int dir){

        for(int d=dir;d<=dir+1;d++){
            if(d>=4) break;
            int nx=x+dx[d];
            int ny=y+dy[d];
            if(nx<0||ny<0||nx>=N||ny>=N){
                continue;
            }
            if(nx==startX && ny==startY&& d==3 && count>=3){
                sum=Math.max(sum,count+1);
                return;
            }
            if(visited[nx][ny]||eaten[dessert[nx][ny]]){
                continue;
            }
            visited[nx][ny]=true;
            eaten[dessert[nx][ny]]=true;
            dfs(count+1,nx,ny,d);
            visited[nx][ny]=false;
            eaten[dessert[nx][ny]]=false;
        }

    }

    public static void input() throws IOException {
        N=Integer.parseInt(br.readLine().trim());
        dessert=new int[N][N];
        startX=startY=sum=0;
        visited=new boolean[N][N];
        eaten=new boolean[101];
        for(int i=0;i<N;i++) {
            st=new StringTokenizer(br.readLine().trim());
            for(int j=0;j<N;j++) {
                dessert[i][j]=Integer.parseInt(st.nextToken());
            }
        }
    }
}
