import java.util.*;
class Solution {
    public static List<String> answer=new ArrayList<>();
    public static List<String> visited=new ArrayList<>();
    public static boolean found=false;
    
    public String[] solution(String[][] tickets) {
        boolean[] usedTickets=new boolean[tickets.length];
        visited.add("ICN");
        dfs(tickets,usedTickets,"ICN",0);
        return answer.toArray(new String[0]);
    }
    public void dfs(String[][] tickets,boolean[] usedTickets,String cur,int depth){
        if(depth==usedTickets.length){
            if(!found||compare()){
                answer=new ArrayList<>(visited);
                found=true;
                return;
            }
        }
        
        for(int i=0;i<tickets.length;i++){
            if(tickets[i][0].equals(cur)&&!usedTickets[i]){
                usedTickets[i]=true;
                visited.add(tickets[i][1]);
                dfs(tickets,usedTickets,tickets[i][1],depth+1);
                usedTickets[i]=false;
                visited.remove(visited.size()-1);
            }
        }
        
    }
    
    public boolean compare(){
        for(int i=0;i<visited.size();i++){
            if(answer.get(i).compareTo(visited.get(i))>0) return true;
            if(answer.get(i).compareTo(visited.get(i))<0) return false;
        }
        return false;
    }
}