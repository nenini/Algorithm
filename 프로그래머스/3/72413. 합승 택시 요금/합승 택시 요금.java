import java.util.*;
class Solution {
    public int solution(int n, int s, int a, int b, int[][] fares) {
        int answer = Integer.MAX_VALUE;
        List<int[]>[] edge=new ArrayList[n+1];
        for(int i=1;i<=n;i++){
            edge[i]=new ArrayList<>();
        }
        
        for(int i=0;i<fares.length;i++){
            int x=fares[i][0];
            int y=fares[i][1];
            int c=fares[i][2];
            edge[x].add(new int[]{y,c});
            edge[y].add(new int[]{x,c});
        }
        int[] dist1=dijkstra(edge,n,s);
        int[] dist2=dijkstra(edge,n,a);
        int[] dist3=dijkstra(edge,n,b);
        
        for(int i=1; i<=n; i++){
            answer = Math.min(answer,
                dist1[i] + dist2[i] + dist3[i]
            );
        }
        return answer;
    }
    
    public int[] dijkstra(List<int[]>[] edge,int n,int start){
        PriorityQueue<int[]> pq=new PriorityQueue<>((a,b)->Integer.compare(a[1],b[1]));
        pq.offer(new int[]{start,0});
        int[] dist=new int[n+1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[start]=0;
        while(!pq.isEmpty()){
            int cur=pq.peek()[0];
            int w=pq.poll()[1];
            if(dist[cur]!=w) continue;
            for(int i=0;i<edge[cur].size();i++){
                int next=edge[cur].get(i)[0];
                int nw=edge[cur].get(i)[1]+w;
                if(dist[next]>nw){
                    dist[next]=nw;
                    pq.offer(new int[]{next,nw});
                }
            }
        }
        return dist;
    }
}