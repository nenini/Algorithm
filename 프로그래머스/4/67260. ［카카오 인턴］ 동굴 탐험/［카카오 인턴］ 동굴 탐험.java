import java.util.*;

class Solution {
    public boolean solution(int n, int[][] path, int[][] order) {
        boolean answer = true;
        
        List<Integer>[] edge=new ArrayList[n];
        for(int i=0;i<n;i++){
            edge[i]=new ArrayList<>();
        }
        
        for(int i=0;i<path.length;i++){
            int a=path[i][0];
            int b=path[i][1];
            edge[a].add(b);
            edge[b].add(a);
        }
        
        List<Integer>[] allOrder=new ArrayList[n];
        for(int i=0;i<n;i++){
            allOrder[i]=new ArrayList<>();
        }
        
        int[] indegree = new int[n];
        
        boolean[] visited=new boolean[n];
        Queue<Integer> q=new ArrayDeque<>();
        q.offer(0);
        
        visited[0]=true;
        while(!q.isEmpty()){
            int cur=q.poll();
            for(int i=0;i<edge[cur].size();i++){
                int next=edge[cur].get(i);
                if(visited[next]) continue;
                
                indegree[next]++;
                allOrder[cur].add(next);
                visited[next]=true;
                q.offer(next);
            }
        }
        
        for(int[] o:order){
            int a=o[0];
            int b=o[1];
            allOrder[a].add(b);
            indegree[b]++;
        }
        return topology(n,indegree,allOrder);
    }
    
    public boolean topology(int n,int[] indegree,List<Integer>[] allOrder){
        Queue<Integer> q=new ArrayDeque<>();
        q.offer(0);
        int count=0;
        
        while(!q.isEmpty()){
            int cur=q.poll();
            count++;
            for(int next:allOrder[cur]){
                if(--indegree[next]==0){
                    q.offer(next);
                }
            }
        }
        
        return count==n;
    }
}