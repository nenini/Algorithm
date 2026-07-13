import java.util.*;
class Solution {
    public int solution(int distance, int[] rocks, int n) {
        
        Arrays.sort(rocks);
        int answer=binarySearch(distance,rocks,n);
        
        return answer;
    }
    
    boolean check(int mid, int distance, int[] rocks,int n){
        int cnt=0;
        int start=0;
        
        for(int i=0;i<rocks.length;i++){
            int cur=rocks[i];
            int dist=cur-start;
            if(dist<mid){
                cnt++;
            }else{
                start=cur;
            }
        }
        int dist=distance-start;
        if(dist<mid){
            cnt++;
        }
        
        if(cnt>n) return false;
        return true;
    } 
    
    int binarySearch(int distance, int[] rocks, int n){
        int start=0;
        int end=distance;
        int ans=0;
        while(start<=end){
            int mid=(start+end)/2;
            
            if(check(mid,distance,rocks,n)){
                start=mid+1;
                ans=mid;
            }else{
                end=mid-1;
            }
        }
        return ans;
    }
}