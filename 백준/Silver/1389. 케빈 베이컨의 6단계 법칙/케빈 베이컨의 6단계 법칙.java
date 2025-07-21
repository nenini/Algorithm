import java.util.*;
public class Main {
    static List<Integer>[] graph;
    static int[] visited;
    static int N, M;
    static int minSum = Integer.MAX_VALUE;
    static int minIndex;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        graph = new ArrayList[N + 1];
        for (int i = 1; i <= N; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int i = 0; i < M; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
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
