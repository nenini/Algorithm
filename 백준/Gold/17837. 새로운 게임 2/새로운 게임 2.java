import java.io.*;
import java.util.*;
public class Main{
	static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int N,K;
	static int[][] arr;
	static int[] dx= {0,0,0,-1,1};
	static int[] dy= {0,1,-1,0,0};
	static Piece[] piece;
	static ArrayList<Integer>[][] base; 
	public static void main(String[] args) throws IOException {
		input();
		for(int i=1;i<=1000;i++) {
			if(simulation()) {
				System.out.println(i);
				return;
			}
		}
		System.out.println(-1);
	}
	
	public static void moveWhite(Piece cur,int nx,int ny,int index) {	
		int sx = cur.x;
	    int sy = cur.y;
	    int size = base[sx][sy].size();
	    
		// 옮기기
		for(int i=index;i<size;i++) {
	        int num = base[sx][sy].get(i);
			base[nx][ny].add(num);
			
			piece[num].x=nx;
			piece[num].y=ny;
		}
		
		base[sx][sy].subList(index,base[sx][sy].size()).clear();
	}
	
	public static void moveRed(Piece cur,int nx,int ny,int index) {
		int sx = cur.x;
	    int sy = cur.y;
	    int size = base[sx][sy].size();
		// 옮기기
		for(int i=size-1;i>=index;i--) {
	        int num = base[sx][sy].get(i);
			base[nx][ny].add(num);
			
			piece[num].x=nx;
			piece[num].y=ny;
		}
		
		base[sx][sy].subList(index,base[sx][sy].size()).clear();
	}
	
	public static boolean simulation() {
		// 각 말 마다
		for(int p=1;p<=K;p++) {
			Piece cur=piece[p];
			int nx=cur.x+dx[cur.d];
			int ny=cur.y+dy[cur.d];
			
			
			//만약 파란색이거나 경계 밖이면
			if(nx<=0||ny<=0||nx>N||ny>N||arr[nx][ny]==2) {
				if(cur.d%2==0) {
					piece[p].d-=1;
				}else {
					piece[p].d+=1;
				}
				nx=piece[p].x+dx[piece[p].d];
				ny=piece[p].y+dy[piece[p].d];
				if(nx < 1 || ny < 1 || nx > N || ny > N || arr[nx][ny] == 2) {
				    continue;
				}
				if(arr[nx][ny]==0||arr[nx][ny]==1) {
					int index=0;

					while(base[cur.x][cur.y].get(index)!=p) index++;
					
					if(arr[nx][ny]==0) moveWhite(cur,nx,ny,index);
					if(arr[nx][ny]==1) moveRed(cur,nx,ny,index);
				}

			}
			//만약 흰색이면
			else if(arr[nx][ny]==0) {
				// 말이 없으면 그냥 움직임
				int index=0;
				
				while(base[cur.x][cur.y].get(index)!=p) index++;
				
				moveWhite(cur,nx,ny,index);
			}
			//만약 빨간색이면
			else {
				// 말이 없으면 그냥 움직임
				int index=0;
				
				while(base[cur.x][cur.y].get(index)!=p) index++;
				
				moveRed(cur,nx,ny,index);

			}
			if(base[nx][ny].size()>=4) return true;
		}
		return false;
	}
	
	
	
	public static void input() throws IOException{
		st=new StringTokenizer(br.readLine().trim());
		N=Integer.parseInt(st.nextToken().trim());
		K=Integer.parseInt(st.nextToken().trim());
		
		arr=new int[N+1][N+1];
		piece=new Piece[K+1];
		base=new ArrayList[N+1][N+1];
		
		for(int i=1;i<=N;i++) {
			for(int j=1;j<=N;j++) {
				base[i][j]=new ArrayList<>();
			}
		}
		
		for(int row=1;row<=N;row++) {
			st=new StringTokenizer(br.readLine().trim());
			for(int col=1;col<=N;col++) {
				arr[row][col]=Integer.parseInt(st.nextToken().trim());
			}
		}
		for(int i=1;i<=K;i++) {
			int r,c,d;
			st=new StringTokenizer(br.readLine().trim());
			r=Integer.parseInt(st.nextToken().trim());
			c=Integer.parseInt(st.nextToken().trim());
			d=Integer.parseInt(st.nextToken().trim());
			piece[i]=new Piece(r,c,d);
			base[r][c].add(i);
		}
	}
}
class Piece{
	int x,y,d;
	public Piece(int x,int y,int d) {
		this.x=x;
		this.y=y;
		this.d=d;
	}
}