import java.util.*;

class Solution {
    public long[] solution(long k, long[] room_number) {
        long[] answer = new long[room_number.length];
        HashMap<Long, Long> map=new HashMap<>();
        
        for(int i=0;i<room_number.length;i++){
            long roomNum=room_number[i];
            
            long cur=roomNum;
            List<Long> visited = new ArrayList<>();

            while(map.containsKey(cur)){
                visited.add(cur);
                cur=map.get(cur);
            }
            for(int j=0;j<visited.size();j++){
                map.put(visited.get(j),cur);
            }
            answer[i]=cur;
            
            map.put(cur,cur+1);
        }
        
        return answer;
    }
}