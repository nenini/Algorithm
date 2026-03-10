import java.io.*;
import java.util.*;

public class Main {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    static int N,M;
    static ArrayList<Integer>[] list;
    static boolean[] visited;
    static boolean result;
	public static void main(String[] args) throws IOException{
		input();
		for(int i=0;i<N;i++) {
			 visited[i] = true;
			 dfs(i, 0);
			 visited[i] = false;
			if(result) break;
		}
		System.out.println(result?1:0);
	}
	
	public static void dfs(int index,int depth) {
		if(depth==4) {
			result=true;
			return;
		}
		for(int i=0;i<list[index].size();i++) {
			int next=list[index].get(i);
			if(!visited[next]) {
				visited[next]=true;
				dfs(next,depth+1);
				visited[next]=false;
			}
		}
	}
	
	public static void input() throws IOException {
		st=new StringTokenizer(br.readLine().trim());
		N=Integer.parseInt(st.nextToken().trim());
		M=Integer.parseInt(st.nextToken().trim());
		
		list=new ArrayList[N];
		visited=new boolean[N];
		for(int i=0;i<N;i++){
			list[i]=new ArrayList<>();
		}
		
		for(int i=0;i<M;i++) {
			st=new StringTokenizer(br.readLine().trim());
			int a=Integer.parseInt(st.nextToken().trim());
			int b=Integer.parseInt(st.nextToken().trim());
			list[a].add(b);
			list[b].add(a);
		}
	}
}
