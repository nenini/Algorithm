import java.io.*;
import java.util.*;

public class Main {
    static List<Integer>[] graph;
    static int[] visited;
    static int N, M;
    static int minSum = Integer.MAX_VALUE;
    static int minIndex;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        graph = (List<Integer>[]) new ArrayList[N + 1];
        for (int i = 1; i <= N; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            graph[a].add(b);
            graph[b].add(a);
        }

        for (int i = 1; i <= N; i++) {
            int sum = bfs(i);
            if (sum < minSum) {
                minSum = sum;
                minIndex = i;
            }
        }

        System.out.println(minIndex);
    }

    static int bfs(int start) {
        visited = new int[N + 1];
        Arrays.fill(visited, -1);
        Queue<Integer> queue = new LinkedList<>();
        queue.add(start);
        visited[start] = 0;
        int total = 0;
        while (!queue.isEmpty()) {
            int curr = queue.poll();
            for (int next : graph[curr]) {
                if (visited[next] == -1) {
                    visited[next] = visited[curr] + 1;
                    total += visited[next];
                    queue.add(next);
                }
            }
        }
        return total;
    }
}
