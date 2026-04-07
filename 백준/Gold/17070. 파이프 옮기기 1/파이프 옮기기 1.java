import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int N;
    static int[][] arr;
    static long[][][] dp;
 
    public static void main(String[] args) throws Exception {
        N = Integer.parseInt(br.readLine().trim());

        arr = new int[N + 1][N + 1];
        dp = new long[N + 1][N + 1][3];

        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= N; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        dp[1][2][0] = 1;

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (arr[i][j] == 1) continue;

                // 가로 -> 가로
                if (j + 1 <= N && arr[i][j + 1] != 1) {
                    dp[i][j + 1][0] += dp[i][j][0];
                }
                // 가로 -> 대각선
                if (i + 1 <= N && j + 1 <= N
                        && arr[i + 1][j + 1] != 1
                        && arr[i + 1][j] != 1
                        && arr[i][j + 1] != 1) {
                    dp[i + 1][j + 1][2] += dp[i][j][0];
                }

                // 세로 -> 세로
                if (i + 1 <= N && arr[i + 1][j] != 1) {
                    dp[i + 1][j][1] += dp[i][j][1];
                }
                // 세로 -> 대각선
                if (i + 1 <= N && j + 1 <= N
                        && arr[i + 1][j + 1] != 1
                        && arr[i + 1][j] != 1
                        && arr[i][j + 1] != 1) {
                    dp[i + 1][j + 1][2] += dp[i][j][1];
                }

                // 대각선 -> 가로
                if (j + 1 <= N && arr[i][j + 1] != 1) {
                    dp[i][j + 1][0] += dp[i][j][2];
                }
                // 대각선 -> 세로
                if (i + 1 <= N && arr[i + 1][j] != 1) {
                    dp[i + 1][j][1] += dp[i][j][2];
                }
                // 대각선 -> 대각선
                if (i + 1 <= N && j + 1 <= N
                        && arr[i + 1][j + 1] != 1
                        && arr[i + 1][j] != 1
                        && arr[i][j + 1] != 1) {
                    dp[i + 1][j + 1][2] += dp[i][j][2];
                }
            }
        }

        System.out.println(dp[N][N][0] + dp[N][N][1] + dp[N][N][2]);
    }
}