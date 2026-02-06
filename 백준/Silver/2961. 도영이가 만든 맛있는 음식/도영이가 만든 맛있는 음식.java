import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;
	static int[] sour;
	static int[] bitter;
	static int ingredientNum;

	public static void main(String[] args) throws NumberFormatException, IOException {
		ingredientNum = Integer.parseInt(br.readLine().trim());
		sour = new int[ingredientNum];
		bitter = new int[ingredientNum];
		for (int ingredientIdx = 0; ingredientIdx < ingredientNum; ingredientIdx++) {
			st = new StringTokenizer(br.readLine().trim());
			sour[ingredientIdx] = Integer.parseInt(st.nextToken());
			bitter[ingredientIdx] = Integer.parseInt(st.nextToken());
		}

		System.out.println(bitMasking());
	}

	public static int bitMasking() {
		int minDifferent = Integer.MAX_VALUE;

		for (int mask = 1; mask < (1 << ingredientNum); mask++) {
			int sumSour = 1;
			int sumBitter = 0;
			for (int i = 0; i < ingredientNum; i++) {
				if ((mask & (1 << i)) != 0) {
					sumSour *= sour[i];
					sumBitter += bitter[i];
				}
			}
			minDifferent = Math.min(Math.abs(sumSour - sumBitter), minDifferent);
		}
		return minDifferent;
	}

}