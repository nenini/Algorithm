import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int N;
	static String text;
	static String pattern;
	static int[] pi;
	static int answer;

	public static void main(String args[]) throws IOException {
		int T = Integer.parseInt(br.readLine().trim());

		for (int tc = 1; tc <= T; tc++) {
			input();

			getPi();
			kmp();
			sb.append("#").append(tc).append(" ").append(answer).append("\n");
		}

		System.out.println(sb);
	}

	public static void kmp() {
		int j = 0;
		for (int i = 0; i < text.length(); i++) {
			while (j > 0 && text.charAt(i) != pattern.charAt(j)) {
				j = pi[j - 1];
			}

			if (text.charAt(i) == pattern.charAt(j)) {
				if (j == pattern.length() - 1) {
					answer++;
					j = pi[j];
				} else {
					j++;
				}
			}
		}
	}

	public static void getPi() {
		int j = 0;
		for (int i = 1; i < pattern.length(); i++) {
			while (j > 0 && pattern.charAt(i) != pattern.charAt(j)) {

				j = pi[j - 1];
			}
			if (pattern.charAt(i) == pattern.charAt(j)) {
				j++;
				pi[i] = j;
			}
		}
	}

	public static void input() throws IOException {
		text = br.readLine().trim();
		pattern = br.readLine().trim();
		pi = new int[pattern.length()];
		answer = 0;
	}
}