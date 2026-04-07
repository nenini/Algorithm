import java.io.*;
import java.util.*;


public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb=new StringBuilder();
	static StringTokenizer st;
	static int N,M;
	static int[][] DP;
	public static void main(String[] args) throws IOException {
        int T=Integer.parseInt(br.readLine().trim());
        for(int tc=1;tc<=T;tc++) {
        	input();
        	sb.append(dfs(M,N)).append('\n');
        }
        
        
        System.out.println(sb);
    }
	
	public static int dfs(int n,int r) {
		if(DP[n][r]>0) return DP[n][r];
		if(r==0 || n==r) return DP[n][r]=1;
		
		return DP[n][r]=dfs(n-1,r-1)+dfs(n-1,r);
	}
    
    public static void input() throws IOException{
    	st=new StringTokenizer(br.readLine().trim());
    	N=Integer.parseInt(st.nextToken().trim());
    	M=Integer.parseInt(st.nextToken().trim());
    	
    	DP=new int[M+1][N+1];
    }
}