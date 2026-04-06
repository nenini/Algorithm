import java.io.*;
import java.util.*;

/**
 *
 * @author SSAFY
 *
 * @see #main(String[])
 *  1. 테스트케이스 수 T를 입력받는다.
 *  2. 각 테스트케이스마다 재료 수 N과 제한 칼로리 L을 입력받는다.
 *  3. 각 재료의 맛 점수와 칼로리를 입력받는다.
 *  4. dp[c]를 칼로리 c 이하에서 얻을 수 있는 최대 맛 점수로 정의한다.
 *  5. 각 재료를 한 번만 사용할 수 있으므로 칼로리를 뒤에서부터 순회하며 dp를 갱신한다.
 *  6. 제한 칼로리 이하에서의 최대 맛 점수를 테스트케이스 번호와 함께 출력한다.
 *
 **/
public class Solution {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws Exception {
        int T = Integer.parseInt(br.readLine().trim());

        for (int tc = 1; tc <= T; tc++) {
            st = new StringTokenizer(br.readLine().trim());
            int N = Integer.parseInt(st.nextToken());
            int L = Integer.parseInt(st.nextToken());

            int[] dp = new int[L + 1];

            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine().trim());
                int taste = Integer.parseInt(st.nextToken());
                int calorie = Integer.parseInt(st.nextToken());

                for (int c = L; c >= calorie; c--) {
                    dp[c] = Math.max(dp[c], dp[c - calorie] + taste);
                }
            }

            sb.append("#").append(tc).append(" ").append(dp[L]).append("\n");
        }

        System.out.print(sb);
    }
}