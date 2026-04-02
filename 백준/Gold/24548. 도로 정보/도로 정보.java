import java.io.*;
import java.util.*;

public class Main{
	
	static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	static Object cur=new Object(0,0,0,0);
	public static void main(String args[]) throws IOException{
		int N=Integer.parseInt(br.readLine().trim());
		String road=br.readLine().trim();
		HashMap<Integer,Integer> hashMap=new HashMap<>();
		hashMap.put(0,1);
		int result=0;
		for(int i=0;i<road.length();i++) {
			char c=road.charAt(i);
			
			cur.plus(c);
			
			int hashCode=getHashCode();
			result+=hashMap.getOrDefault(hashCode,0);
			hashMap.put(hashCode,hashMap.getOrDefault(hashCode,0)+1);
			
		}
		System.out.println(result);
	}
	
	public static int getHashCode() {
		int hashInt=1000*cur.T+100*cur.G+10*cur.F+cur.P;
		return hashInt;
	}
}

class Object{
	int T;
	int G;
	int F;
	int P;
	
	public Object(int T,int G,int F,int P) {
		this.T=T;
		this.G=G;
		this.F=F;
		this.P=P;
	}
	
	public void plus(char c) {
		if(c=='T') {
			T++;
			T%=3;
		}else if(c=='G') {
			G++;
			G%=3;
		}else if(c=='F') {
			F++;
			F%=3;
		}else {
			P++;
			P%=3;
		}
	}
}