import java.io.*;
import java.util.*;

public class Solution {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static int N,M;
    static ArrayList<Point> home;
    public static void main(String[] args) throws Exception {
        int T = Integer.parseInt(br.readLine().trim());

        for (int tc = 1; tc <= T; tc++) {
            input();
            
            sb.append("#").append(tc).append(" ").append(findMaxHomeCount()).append("\n");
        }

        System.out.print(sb);
    }
    
    public static int findMaxHomeCount() {
    	// 각 칸별로 K만큼 운영 크기 -> 포함되는 집 개수와 손해를 보지 않는지 확인
    	int maxHomeCount=0;
    	for(int row=0;row<N;row++) {
    		for(int col=0;col<N;col++) {
    			for(int k=1;k<2*N;k++) {
    		    	int operatePrice=k*k+(k-1)*(k-1);
    		    	int homeCount=includeHomeCount(row,col,k);
    		    	if(operatePrice<=(homeCount*M)) {
    		    		maxHomeCount=Math.max(maxHomeCount, homeCount);
    		    	}
    			}
    		}
    	}
    	return maxHomeCount;
    }
    
    public static int includeHomeCount(int r,int c,int k) {
    	int homeCount=0;
    	for(int homeIndex=0;homeIndex<home.size();homeIndex++) {
    		if(isInDistance(k,r,c,home.get(homeIndex).x,home.get(homeIndex).y)) {
    			homeCount++;
    		}
    	}
    	return homeCount;
    	
    }
    
    public static boolean isInDistance(int k,int r1,int c1,int r2,int c2) {
    	int distance= Math.abs(r1-r2)+Math.abs(c1-c2);
    	return distance<=(k-1);
    }
    

    
    public static void input() throws Exception{
        st = new StringTokenizer(br.readLine().trim());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        
        home=new ArrayList<>();
        
        for(int row=0;row<N;row++) {
        	st=new StringTokenizer(br.readLine().trim());
        	for(int col=0;col<N;col++) {
        		int num=Integer.parseInt(st.nextToken().trim());
        		if(num==1) {
        			home.add(new Point(row,col));
        		}
        	}
        }

    }
}

class Point{
	int x;
	int y;
	public Point(int x,int y) {
		this.x=x;
		this.y=y;
	}
}