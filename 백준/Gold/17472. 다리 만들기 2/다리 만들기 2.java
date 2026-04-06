import java.io.*;
import java.util.*;

/**
 *
 * @author SSAFY
 *
 * @see #main(String[])
 *  1. 지도의 크기와 섬/바다 정보를 입력받는다.
 *  2. BFS를 이용해 각 섬에 번호를 붙이고, 가장자리 좌표를 저장한다.
 *  3. 가장자리 좌표들로부터 만들 수 있는 다리 후보를 탐색한다.
 *  4. 다리 길이를 기준으로 정렬한 뒤 크루스칼 알고리즘으로 최소 연결 비용을 구한다.
 *  5. 모든 섬이 연결되면 총 길이를, 불가능하면 -1을 출력한다.
 *
 * @see #bfs(int, int)
 *  1. 하나의 섬을 BFS로 탐색하며 같은 섬 칸에 동일한 번호를 부여한다.
 *  2. 상하좌우 중 바다와 인접한 칸은 가장자리 좌표로 저장한다.
 *
 * @see #findBridge()
 *  1. 각 가장자리 좌표에서 4방향으로 직선 탐색을 수행한다.
 *  2. 다른 섬을 만났을 때 다리 길이가 2 이상이면 다리 후보로 저장한다.
 *
 * @see #findRoot(int)
 *  1. 유니온 파인드에서 해당 정점의 대표 부모를 찾는다.
 *
 * @see #unionFind(int, int)
 *  1. 두 섬이 속한 집합의 대표 부모를 찾는다.
 *  2. 서로 다른 집합이면 합치고 true를 반환한다.
 *  3. 이미 같은 집합이면 false를 반환한다.
 *
 * @see #kruskal()
 *  1. 다리 길이가 짧은 순서대로 확인한다.
 *  2. 서로 다른 섬을 연결하는 다리만 선택한다.
 *  3. 선택한 다리 수와 총 길이를 누적한다.
 */
public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int N, M;
    static int[][] arr = new int[10][10];
    static boolean[][] visited = new boolean[10][10];
    static int[] parent = new int[7];

    static int[] dx = {0, 0, 1, -1};
    static int[] dy = {-1, 1, 0, 0};

    static int islandNum = 0;
    static int bridgeCnt = 0;
    static int result = 0;

    static List<int[]> edge = new ArrayList<>(); // {x, y}
    static List<Bridge> bridge = new ArrayList<>();

    static class Bridge implements Comparable<Bridge> {
        int distance;
        int start;
        int end;

        Bridge(int distance, int start, int end) {
            this.distance = distance;
            this.start = start;
            this.end = end;
        }

        @Override
        public int compareTo(Bridge o) {
            return Integer.compare(this.distance, o.distance);
        }
    }

    public static void bfs(int x, int y) {
        Queue<int[]> q = new ArrayDeque<>();
        q.offer(new int[]{x, y});
        visited[x][y] = true;
        arr[x][y] = islandNum;

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int cx = cur[0];
            int cy = cur[1];

            boolean check = false;

            for (int d = 0; d < 4; d++) {
                int nnx = cx + dx[d];
                int nny = cy + dy[d];
                if (nnx < 0 || nny < 0 || nnx >= N || nny >= M) continue;
                if (arr[nnx][nny] == 0) {
                    check = true;
                }
            }

            if (check) {
                edge.add(new int[]{cx, cy});
            }

            for (int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];

                if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                if (visited[nx][ny] || arr[nx][ny] == 0) continue;

                q.offer(new int[]{nx, ny});
                visited[nx][ny] = true;
                arr[nx][ny] = islandNum;
            }
        }
    }

    public static void findBridge() {
        for (int e = 0; e < edge.size(); e++) {
            int x = edge.get(e)[0];
            int y = edge.get(e)[1];

            for (int d = 0; d < 4; d++) {
                int nx = x;
                int ny = y;

                while (true) {
                    nx += dx[d];
                    ny += dy[d];

                    if (nx < 0 || ny < 0 || nx >= N || ny >= M) break;
                    if (arr[nx][ny] == arr[x][y]) break;

                    if (arr[nx][ny] != 0 && arr[x][y] != arr[nx][ny]) {
                        int distance;
                        if (x == nx) {
                            distance = Math.abs(ny - y) - 1;
                        } else {
                            distance = Math.abs(nx - x) - 1;
                        }

                        if (distance < 2) break;

                        bridge.add(new Bridge(distance, arr[x][y], arr[nx][ny]));
                        break;
                    }
                }
            }
        }
    }

    public static int findRoot(int x) {
        if (parent[x] == x) return x;
        return parent[x] = findRoot(parent[x]);
    }

    public static boolean unionFind(int start, int end) {
        int sp = findRoot(start);
        int ep = findRoot(end);

        if (sp == ep) return false;

        if (sp < ep) {
            parent[ep] = sp;
        } else {
            parent[sp] = ep;
        }
        return true;
    }

    public static void kruskal() {
        for (int i = 1; i <= islandNum; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < bridge.size(); i++) {
            Bridge b = bridge.get(i);

            if (unionFind(b.start, b.end)) {
                bridgeCnt++;
                result += b.distance;
            }
        }
    }

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (arr[i][j] != 0 && !visited[i][j]) {
                    islandNum++;
                    bfs(i, j);
                }
            }
        }

        findBridge();
        Collections.sort(bridge);
        kruskal();

        if (bridgeCnt == islandNum - 1) {
            System.out.println(result);
        } else {
            System.out.println(-1);
        }
    }
}