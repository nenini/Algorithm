import java.io.*;
import java.util.*;

public class Solution {
    static final int N = 100;
    static int[][] map = new int[N][N];
    static boolean[][] visited = new boolean[N][N];

    static final int[] dx = {1, -1, 0, 0};
    static final int[] dy = {0, 0, 1, -1};

    static class Node {
        int x, y;
        Node(int x, int y) { this.x = x; this.y = y; }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        for (int tc = 1; tc <= 10; tc++) {
            // 테스트케이스 번호
            int t = Integer.parseInt(br.readLine().trim());

            int sx = -1, sy = -1;

            for (int i = 0; i < N; i++) {
                String line = br.readLine().trim();
                for (int j = 0; j < N; j++) {
                    int v = line.charAt(j) - '0';
                    map[i][j] = v;
                    visited[i][j] = false;
                    if (v == 2) { sy = i; sx = j; } 
                }
            }

            int ans = bfs(sx, sy);
            sb.append("#").append(t).append(" ").append(ans).append("\n");
        }

        System.out.print(sb.toString());
    }

    static int bfs(int sx, int sy) {
        ArrayDeque<Node> q = new ArrayDeque<>();
        q.add(new Node(sx, sy));
        visited[sy][sx] = true;

        while (!q.isEmpty()) {
            Node cur = q.poll();
            int x = cur.x, y = cur.y;

            if (map[y][x] == 3) return 1;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if (visited[ny][nx]) continue;
                if (map[ny][nx] == 1) continue; // 벽

                visited[ny][nx] = true;
                q.add(new Node(nx, ny));
            }
        }
        return 0;
    }
}