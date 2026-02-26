import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int N;
    static Pair[] arr;
    static int[][] DP;
    public static void main(String[] args) throws NumberFormatException, IOException {
		input();
		for(int len=2;len<=N;len++) {
			for(int i=0;i<=N-len;i++) {
				int j=i+len-1;
				for(int k=i;k<j;k++) {
					DP[i][j]=Math.min(DP[i][j], DP[i][k]+DP[k+1][j]+(arr[i].row * arr[k].col * arr[j].col)); 
				}
			}
		}
		System.out.println(DP[0][N-1]);
		
		
	}
    public static void input() throws NumberFormatException, IOException {
    	N=Integer.parseInt(br.readLine().trim());
    	arr=new Pair[N];
    	DP=new int[N][N];
    	for(int i=0;i<N;i++) {
    		Arrays.fill(DP[i], (int) 1e9);
    		DP[i][i]=0;
    	}
    	for(int i=0;i<N;i++) {
    		st=new StringTokenizer(br.readLine().trim());
    		arr[i]=new Pair(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()));
    	}
    }
    
}



class Pair{
	int row;
	int col;
	public Pair(int row, int col) {
		this.row=row;
		this.col=col;
	}
}