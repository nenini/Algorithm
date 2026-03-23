import java.io.*;
import java.util.*;
public class Main{
	
	// 직사각형 보드, 빨간 구슬, 파란 구슬 => 빨간 구슬을 빼내는 게임
	//NxM, 파란 구슬이 들어가면 안됨
	// 상하좌우로 기울임
	// 빨갈 구슬과 파란구슬이 동시에 빠져도 실패, 파란구슬이 빠져도 실패 => 빨간 구슬만 성공
	// 10번 이하로 빨간 구슬 구멍을 통해 빼낼 수 있는지 확인
	
	static BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int N,M;
	static char[][] arr;
	static Pair blue,red,hole;
	static int[] dx= {-1,1,0,0};
	static int[] dy= {0,0,-1,1};
	public static void main(String args[]) throws IOException{
		input();
		if(dfs(0)) System.out.println(1);
		else System.out.println(0);
	}
	
	public static boolean dfs(int depth) {
		if(depth==10) {
			return false;
		}
		for(int i=0;i<4;i++) {
			Pair tempBlue = new Pair(blue.x, blue.y);
			Pair tempRed = new Pair(red.x, red.y);
			
			int simulationRet=simulation(i);
			if(simulationRet==0) {
				return true;
			}else if(simulationRet==1) {
				blue=tempBlue;
				red=tempRed;
				continue;
			}
			if (blue.x == tempBlue.x && blue.y == tempBlue.y
			    && red.x == tempRed.x && red.y == tempRed.y) {
			    blue = tempBlue;
			    red = tempRed;
			    continue;
			}
			
			if(dfs(depth+1)) {
				return true;
			}
			blue=tempBlue;
			red=tempRed;
			
		}
		return false;
	}
	
	public static int simulation(int dir) {
		// 0: 빨간색만 통과/ 1: 파란색이 통과해버림 / 2: 둘다 통과 X
		if(isBlueFront(dir)) {
			moveBlue(dir);
			moveRed(dir);
		}else {
			moveRed(dir);
			moveBlue(dir);
		}
		
		if(blue.x==-1&&blue.y==-1) {
			return 1;
		}else if(red.x==-1&&red.y==-1) {
			return 0;
		}else {
			return 2;
		}
		
	}
	public static void moveBlue(int dir) {
		int x=blue.x;
		int y=blue.y;
		while(true) {
			x+=dx[dir];
			y+=dy[dir];
			if(x<0||y<0||x>=N||y>=M) break;
			if(arr[x][y]=='#') break;
			if(x==red.x&&y==red.y) break;
			if(arr[x][y]=='O') {
				blue.x=-1;
				blue.y=-1;
				return;
			}
		}
		blue.x=x-dx[dir];
		blue.y=y-dy[dir];
	}
	public static void moveRed(int dir) {
		int x=red.x;
		int y=red.y;
		while(true) {
			x+=dx[dir];
			y+=dy[dir];
			if(x<0||y<0||x>=N||y>=M) break;
			if(arr[x][y]=='#') break;
			if(x==blue.x&&y==blue.y) break;
			if(arr[x][y]=='O') {
				red.x=-1;
				red.y=-1;
				return;
			}
		}
		red.x=x-dx[dir];
		red.y=y-dy[dir];
	}
	
	public static boolean isBlueFront(int dir) {
		if(dir==0) {
			if(blue.x<red.x) return true;
		}else if(dir==1) {
			if(blue.x>red.x) return true;
		}else if(dir==2) {
			if(blue.y<red.y) return true;
		}else {
			if(blue.y>red.y) return true;
		}
		return false;
	
	}
	
	public static void input() throws IOException{
		st=new StringTokenizer(br.readLine().trim());
		N=Integer.parseInt(st.nextToken().trim());
		M=Integer.parseInt(st.nextToken().trim());
		
		arr=new char[N][M];
		
		for(int i=0;i<N;i++) {
			String str=br.readLine().trim();
			for(int j=0;j<M;j++) {
				arr[i][j]=str.charAt(j);
				
				if(arr[i][j]=='R') {
					red=new Pair(i,j);
				}else if(arr[i][j]=='B') {
					blue=new Pair(i,j);
				}else if(arr[i][j]=='O') {
					hole=new Pair(i,j);
				}
				
			}
		}
	}
}

class Pair{
	int x,y;
	public Pair(int x,int y) {
		this.x=x;
		this.y=y;
	}
	
}