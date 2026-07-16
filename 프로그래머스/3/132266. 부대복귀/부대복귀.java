import java.util.*;
class Solution {
    public int[] solution(int n, int[][] roads, int[] sources, int destination) {
        int[] answer = new int[sources.length];
        List<Integer>[] road=new ArrayList[n+1];
        
        for(int i=1;i<=n;i++){
            road[i]=new ArrayList<>();
        }
        
        
        for(int i=0;i<roads.length;i++){
            int a=roads[i][0];
            int b=roads[i][1];
            road[a].add(b);
            road[b].add(a);
        }
        
        int[] dist=new int[n+1];
        Arrays.fill(dist,-1);
        bfs(n,road,destination,dist);
        
        for(int i=0;i<sources.length;i++){
            answer[i]=dist[sources[i]];
        }
        
        return answer;
    }
    
    void bfs(int n, List<Integer>[] road, int destination,int[] dist){
        Queue<Integer> q=new ArrayDeque<>();
        q.offer(destination);
        dist[destination]=0;
        
        while(!q.isEmpty()){
            int cur=q.poll();
            
            for(int i=0;i<road[cur].size();i++){
                int next=road[cur].get(i);
                
                if(dist[next]!=-1) continue;
                
                q.offer(next);
                dist[next]=dist[cur]+1;
            }
        }
    }
}

