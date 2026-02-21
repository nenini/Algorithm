import java.io.*;
import java.util.*;

public class Main {
    static int N, M;
    static ArrayList<Integer>[] adj;
    static int[] indegree;
    static ArrayList<Integer> result = new ArrayList<>();

    static void topology() {
        ArrayDeque<Integer> q = new ArrayDeque<>();

        for (int i = 1; i <= N; i++) {
            if (indegree[i] == 0) q.add(i);
        }

        for (int i = 1; i <= N; i++) {
            int curr = q.poll(); 
            result.add(curr);

            for (int next : adj[curr]) {
                if (--indegree[next] == 0) q.add(next);
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        adj = new ArrayList[N + 1];
        indegree = new int[N + 1];
        for (int i = 1; i <= N; i++) adj[i] = new ArrayList<>();

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            adj[a].add(b);
            indegree[b]++;
        }

        topology();

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < N; i++) {
            sb.append(result.get(i)).append(' ');
        }
        System.out.print(sb.toString());
    }
}