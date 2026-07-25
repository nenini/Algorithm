import java.util.*;

class Solution {
    public int solution(int n, int[][] costs) {
        int answer = 0;
        int[] parent=new int[n];
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        Arrays.sort(costs,(a,b)->Integer.compare(a[2],b[2]));
        for(int i=0;i<costs.length;i++){
            int a=costs[i][0];
            int b=costs[i][1];
            int cost=costs[i][2];
            
            if(unionFind(parent,a,b)){
                answer+=cost;
                n--;
            }
            if(n==1) break;
            
        }
        
        return answer;
    }
    
    public boolean unionFind(int[] parent,int a,int b){
        int ap=findParent(parent,a);
        int bp=findParent(parent,b);
        if(ap==bp) return false;
        
        if(ap<bp) parent[bp]=ap;
        else parent[ap]=bp;
        return true;
    }
    
    public int findParent(int[] parent,int x){
        if(x==parent[x]) return x;
        return parent[x]=findParent(parent,parent[x]);
    }
}
