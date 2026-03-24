import java.io.*;
import java.util.*;

public class Main{
	static BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb=new StringBuilder();
	static StringTokenizer st;
	static int n;
	static int[] arr;
	static boolean[] visited;
	static boolean[] isEnd;
	static int count;
	public static void main(String args[]) throws IOException{
		int T=Integer.parseInt(br.readLine().trim());
		for(int testcase=0;testcase<T;testcase++) {
			input();
			for(int i=1;i<=n;i++) {
				if(!visited[i]) {
					dfs(i);
				}
			}
			sb.append(n-count).append('\n');
		}
		System.out.println(sb);
	}
	
	public static void dfs(int cur) {
		visited[cur]=true;
		int next=arr[cur];
		if(!visited[next]) {
			dfs(next);
		}else if(!isEnd[next]) {
			count++;
			for (int i = next; i != cur; i = arr[i]) {
			    count++;
			}
		}
		isEnd[cur]=true;
	}
	
	public static void input() throws IOException{
		n=Integer.parseInt(br.readLine().trim());
		
		count=0;
		arr=new int[n+1];
		
		visited=new boolean[n+1];
		isEnd=new boolean[n+1];
		
		st=new StringTokenizer(br.readLine().trim());
		for(int i=1;i<=n;i++) {
			int num=Integer.parseInt(st.nextToken().trim());
			arr[i]=num;
		}
	}
}