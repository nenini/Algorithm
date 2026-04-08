import java.io.*;
import java.util.*;


public class Solution {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int N, K;
    static int[][] item;
    static int[] DP;

    public static void main(String[] args) throws Exception {
        int T = Integer.parseInt(br.readLine().trim());

        for (int tc = 1; tc <= T; tc++) {
            input();

            for (int i = 0; i < N; i++) {
                for (int j = K; j >= item[i][0]; j--) {
                    DP[j] = Math.max(DP[j], DP[j - item[i][0]] + item[i][1]);
                }
            }

            sb.append("#").append(tc).append(" ").append(DP[K]).append("\n");
        }

        System.out.print(sb);
    }

    public static void input() throws Exception {
        st = new StringTokenizer(br.readLine().trim());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        item = new int[N][2];
        DP = new int[K + 1];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine().trim());
            item[i][0] = Integer.parseInt(st.nextToken()); // 부피
            item[i][1] = Integer.parseInt(st.nextToken()); // 가치
        }
    }
}