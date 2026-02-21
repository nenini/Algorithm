import java.io.*;
import java.util.*;

public class Solution {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st ;
    static int V,E;
    static StringBuilder sb=new StringBuilder();
    static int[] indegree;
    static ArrayList<Integer>[] adjList;

    public static void main(String[] args) throws Exception {
        for(int testcase=1;testcase<=10;testcase++) {
            sb.append("#").append(testcase).append(" ");
            input();
            topology();
            sb.append("\n");
        }
        System.out.println(sb);

    }

    public static void topology(){
        Queue<Integer> q=new ArrayDeque<>();
        for(int i=1;i<=V;i++){
            if(indegree[i]==0){
                q.add(i);
            }
        }
        while(!q.isEmpty()){
            int u=q.poll();
            sb.append(u).append(" ");
            for(int v:adjList[u]){
                if(--indegree[v]==0){
                    q.add(v);
                }
            }
        }
    }

    public static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());
        indegree = new int[V+1];
        adjList = new ArrayList[V+1];
        for(int i=1;i<=V;i++) {
            adjList[i] = new ArrayList<>();
        }
        st = new StringTokenizer(br.readLine().trim());
        for(int i=0;i<E;i++) {
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            adjList[a].add(b);
            indegree[b]++;
        }
    }
}
