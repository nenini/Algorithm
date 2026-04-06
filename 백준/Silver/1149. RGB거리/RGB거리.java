import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int N = Integer.parseInt(br.readLine());
        int[][] dp = new int[N + 1][3];

        for (int i = 1; i <= N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            
            int r = Integer.parseInt(st.nextToken());
            int g = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            dp[i][0] = r + Math.min(dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] = g + Math.min(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = b + Math.min(dp[i - 1][0], dp[i - 1][1]);
        }

        int answer = Math.min(dp[N][0], Math.min(dp[N][1], dp[N][2]));
        System.out.println(answer);
    }
}