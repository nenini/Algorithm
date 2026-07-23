import java.util.*;
class Solution {

    public long solution(int[] a, int[][] edges) {
        long answer=0;
        long sum=0;
        List<Integer>[] edgeList=new ArrayList[a.length];
        for(int i=0;i<a.length;i++){
            edgeList[i]=new ArrayList<>();
        }
        
        for(int i=0;i<edges.length;i++){
            edgeList[edges[i][0]].add(edges[i][1]);
            edgeList[edges[i][1]].add(edges[i][0]);
        }
        
        int[] parent = new int[a.length];
        Arrays.fill(parent,-1);
        long[] weight = new long[a.length];

        for(int i=0;i<a.length;i++){
           weight[i] = a[i];

            sum+=a[i];
        }
        if(sum!=0) return -1;
        
        Queue<Integer> node=new ArrayDeque<>();
        node.offer(0);
        int[] order = new int[a.length];
        int idx=0;
        while(!node.isEmpty()){
            int cur=node.poll();
            order[idx++]=cur;
            
            for(int i=0;i<edgeList[cur].size();i++){
                int next=edgeList[cur].get(i);
                if(next==parent[cur]) continue;

                parent[next]=cur;
                node.offer(next);
            }
        }
        for(int i=order.length-1;i>0;i--){
            int cur=order[i];
            int p=parent[cur];
            
            answer+=Math.abs(weight[cur]);
            weight[p]+=weight[cur];
        }
        
        // dfs(parent,a,0,edgeList);
        return answer;
    }
    
    
}