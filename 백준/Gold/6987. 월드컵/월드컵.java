import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int[][] arr;
	static boolean result;

	public static void main(String[] args) throws Exception {

		for (int tc = 1; tc <= 4; tc++) {
			input();
			dfs(0, 1);
			sb.append(result ? 1 : 0).append(" ");
		}
		System.out.print(sb);
	}

	public static void dfs(int index1, int index2) {
		if (index1 == 5) {
			for (int t = 0; t < 6; t++) {
				if (arr[t][0] != 0 || arr[t][1] != 0 || arr[t][2] != 0)
					return;
			}
			result = true;
			return;
		}
		for (int i = 0; i < 3; i++) {

			if (arr[index1][i] > 0 && arr[index2][2 - i] > 0) {
				arr[index1][i] -= 1;
				arr[index2][2 - i] -= 1;
				if (index2 == 5) {
					dfs(index1 + 1, index1 + 2);
				} else {
					dfs(index1, index2 + 1);
				}
				arr[index1][i] += 1;
				arr[index2][2 - i] += 1;
			}

		}
	}

	public static void input() throws NumberFormatException, IOException {
		arr = new int[6][3];
		result = false;
		st = new StringTokenizer(br.readLine().trim());
		for (int j = 0; j < 6; j++) {
			arr[j][0] = Integer.parseInt(st.nextToken());
			arr[j][1] = Integer.parseInt(st.nextToken());
			arr[j][2] = Integer.parseInt(st.nextToken());
		}

	}

}
