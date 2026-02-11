import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int R, C;
	static int[][] arr;
	static int[] dx = { -1, 0, 1 };
	static int[] dy = { 1, 1, 1 };
	static boolean[][] visited;

	public static void main(String[] args) throws Exception {
		int result = 0;
		input();
		for (int i = 0; i < R; i++) {
			if (dfs(i, 0)) {
				result++;
			}
		}
		System.out.println(result);
	}

	public static boolean dfs(int x, int y) {
		if (y == C - 1) {
			return true;
		}

		for (int i = 0; i < 3; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= R || ny >= C)
				continue;
			if (visited[nx][ny])
				continue;
			if (arr[nx][ny] == 'x')
				continue;
			visited[nx][ny] = true;
			if (dfs(nx, ny))
				return true;
		}
		return false;
	}

	public static void input() throws NumberFormatException, IOException {
		st = new StringTokenizer(br.readLine().trim());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		arr = new int[R][C];
		visited = new boolean[R][C];
		for (int i = 0; i < R; i++) {
			String input = br.readLine().trim();
			for (int j = 0; j < C; j++) {
				arr[i][j] = input.charAt(j);
			}
		}

	}

}
