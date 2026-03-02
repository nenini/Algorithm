import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * @see #main(String[])
 * 
 */
public class Main{
	static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb=new StringBuilder();
	static StringTokenizer st;
	
	static int round; // 이닝 수
	static int[][] result; //각 이닝  타수 결
	static int[] playerOrder;
	static boolean[] visited;
	static int maxScore=0;
	public static void main(String[] args) throws NumberFormatException, IOException {
		input();
		playerOrder[3]=0;
		visited[0]=true;
		permutation(0);
		System.out.println(maxScore);
	}
	
	public static void permutation(int index) {
		if(index==9) {
			maxScore=Math.max(maxScore, play());
			return;
		}
		if(index==3) {
			// 4번 타자는 1번 선수 고정
			permutation(index+1);
			return;
		}
		for(int playerIdx=1;playerIdx<9;playerIdx++) {
			if(!visited[playerIdx]) {
				visited[playerIdx]=true;
				playerOrder[index]=playerIdx;
				permutation(index+1);
				visited[playerIdx]=false;
			}
		}
	}
	
	public static int play() {
		int index=0; // 타자 순서
		int outCnt=0;
		int base=0; //비트로 표현, 
		int score=0;
		for(int roundIdx=0;roundIdx<round;roundIdx++) {
			outCnt=0;
			base=0;
			while(outCnt<3) {
				int hit=result[roundIdx][playerOrder[index]];
				if(hit==0) {
					outCnt++;
				}else if(hit==4) {
					score+=Integer.bitCount(base)+1;
					base=0;
				}else {
					base<<= hit;
					base|=(1<<(hit-1));
					score+=Integer.bitCount(base>>3);
					base&=0b111;
				}
				index=(index+1)%9;
				
			}	
		}
		return score;
		
	}
	
	
	
	public static void input() throws NumberFormatException, IOException {
		round=Integer.parseInt(br.readLine().trim());
		result=new int[round][9];
		playerOrder=new int[9];
		visited=new boolean[9];
		for(int roundIdx=0;roundIdx<round;roundIdx++) {
			st=new StringTokenizer(br.readLine().trim());
			for(int playerIdx=0;playerIdx<9;playerIdx++) {
				result[roundIdx][playerIdx]=Integer.parseInt(st.nextToken());
			}
		}
	}
}
