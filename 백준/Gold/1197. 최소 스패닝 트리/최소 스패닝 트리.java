import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
   
    static int V,E;
    static PriorityQueue<int[]> pq;
    static int[] parent;
    
    public static void main(String[] args) throws IOException{
		input();
		System.out.println(kruskal());
	}
    
    
    public static int findParent(int a) {
    	if(parent[a]==a) return a;
    	else return parent[a]=findParent(parent[a]);
    }
    
    public static boolean unionFind(int a,int b) {
    	int parentA=findParent(a);
    	int parentB=findParent(b);
    	
    	if(parentA==parentB) return true;
    	if(parentA<parentB) parent[parentB]=parentA;
    	else parent[parentA]=parentB;
    	return false;
    }
    
    public static long kruskal() {
    	int count=0;
    	long sum=0;
    	while(!pq.isEmpty()) {
    		int[] edge=pq.poll();
    		if(!unionFind(edge[0], edge[1])) {
    			count++;
    			sum+=edge[2];
    		}
    		if(count==V-1) break;
    	}
    	return  sum;
    }
    
    public static void input() throws IOException{
		st=new StringTokenizer(br.readLine().trim());
    	V=Integer.parseInt(st.nextToken().trim());
    	E=Integer.parseInt(st.nextToken().trim());

    	pq=new PriorityQueue<>((a,b)->Integer.compare(a[2], b[2]));
    	parent=new int[V+1];
    	for (int i = 1; i <= V; i++) {
    	    parent[i] = i;
    	}
    	for(int edgeIdx=0;edgeIdx<E;edgeIdx++) {
    		st=new StringTokenizer(br.readLine().trim());
    		int A=Integer.parseInt(st.nextToken().trim());
    		int B=Integer.parseInt(st.nextToken().trim());
    		int C=Integer.parseInt(st.nextToken().trim());
    		pq.add(new int[] {A,B,C});
    	}	    	
    }
}
