import java.util.*;
public class Solution {
    public long solution(int[][] land, int P, int Q) {
        long answer = -1;
        int minNum=Integer.MAX_VALUE;
        int maxNum=Integer.MIN_VALUE;
        for(int i=0;i<land.length;i++){
            for(int j=0;j<land[0].length;j++){
                minNum=Math.min(minNum,land[i][j]);
                maxNum=Math.max(maxNum,land[i][j]);
            }
        }
        
        int start=0;
        int end=maxNum;
        
        while(start<=end){
            int middle=(start+end)/2;
            long curCost=getCost(land,P,Q,middle);
            long nextCost=getCost(land,P,Q,middle+1);
            if(curCost<=nextCost){
                end=middle-1;
                answer=curCost;
            }else{
                start=middle+1;
            }
        }
        
        return answer;
    }
    
    public long getCost(int[][] land, int P, int Q,int height){
        long cost=0;
        for(int i=0;i<land.length;i++){
            for(int j=0;j<land[0].length;j++){
                if(land[i][j]<height){
                    cost+= (long)(height-land[i][j])*P;
                }
                if(land[i][j]>height){
                    cost+= (long)(land[i][j]-height)*Q;
                }
            }
        }
        return cost;
    }
}