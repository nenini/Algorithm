import java.io.*;
import java.util.*;

class Solution {
    public long solution(int a, int b, int[] g, int[] s, int[] w, int[] t) {
        long answer = -1;
        long start=0;
        long end=(long)5e14;
        while(start<=end){
            long  middle=(start+end)/2;
            if(check(middle, a,b,g,s,w,t)){
                end=middle-1;
                answer=middle;
            }else{
                start=middle+1;
            }
        }
        return answer;
    }
    
    public boolean check( long T, int a, int b, int[] g, int[] s, int[] w, int[] t){
        long  totalGold=0;
        long  totalSilver=0;
        long  total=0;
        
        for(int i=0;i<g.length;i++){
            
            long cnt=T/(t[i]*2L);
            if(T%(t[i]*2)>=t[i]) cnt++;
            
            long  capacity=cnt*w[i];
            long  gold=Math.min(g[i],capacity);
            long  silver=Math.min(s[i],capacity);
            long  goldAndSilver=Math.min((long)g[i]+s[i],capacity);
            totalGold+=gold;
            totalSilver+=silver;
            total+=goldAndSilver;
        }
        
        if(a<=totalGold && b<=totalSilver && (a+b)<=total){
            return true;
        }
        return false;
    }
}