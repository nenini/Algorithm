import java.io.*;
import java.util.*;

public class Solution {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int N;
    static Point company, home;
    static Point[] customer;
    static int[][] dp;
    static final int INF = (int)1e9;

    public static void main(String[] args) throws Exception {
        int T = Integer.parseInt(br.readLine().trim());

        for (int tc = 1; tc <= T; tc++) {
            input();
            int answer = solve();
            sb.append("#").append(tc).append(" ").append(answer).append('\n');
        }

        System.out.print(sb);
    }

    static int solve() {
        int size = 1 << N;
        dp = new int[size][N];

        for (int i = 0; i < size; i++) {
            Arrays.fill(dp[i], INF);
        }

        // 회사 -> 각 고객
        for (int i = 0; i < N; i++) {
            dp[1 << i][i] = dist(company, customer[i]);
        }

        // mask: 방문한 고객 집합
        // i: 현재 마지막 고객
        for (int mask = 0; mask < size; mask++) {
            for (int i = 0; i < N; i++) {
                if (dp[mask][i] == INF) continue;
                if ((mask & (1 << i)) == 0) continue;

                for (int j = 0; j < N; j++) {
                    if ((mask & (1 << j)) != 0) continue;

                    int nextMask = mask | (1 << j);
                    dp[nextMask][j] = Math.min(
                        dp[nextMask][j],
                        dp[mask][i] + dist(customer[i], customer[j])
                    );
                }
            }
        }

        int allVisited = (1 << N) - 1;
        int answer = INF;

        // 마지막 고객 -> 집
        for (int i = 0; i < N; i++) {
            answer = Math.min(answer, dp[allVisited][i] + dist(customer[i], home));
        }

        return answer;
    }

    static int dist(Point a, Point b) {
        return Math.abs(a.x - b.x) + Math.abs(a.y - b.y);
    }

    static void input() throws Exception {
        N = Integer.parseInt(br.readLine().trim());
        st = new StringTokenizer(br.readLine());

        company = new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        home = new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));

        customer = new Point[N];
        for (int i = 0; i < N; i++) {
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            customer[i] = new Point(x, y);
        }
    }

    static class Point {
        int x, y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}