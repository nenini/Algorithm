import java.util.*;

class Solution {
    public int solution(int[] food_times, long k) {
        List<Pair> food = new ArrayList<>();
        int answer = 0;

        for (int i = 0; i < food_times.length; i++) {
            food.add(new Pair(i, food_times[i]));
        }

        Collections.sort(food);

        int curN = 0;
        int total = food_times.length;

        for (int i = 0; i < food.size(); i++) {
            int idx = food.get(i).idx;
            int f = food.get(i).f;

            long n = (long) (total - i) * (f - curN);

            if (n <= k) {
                k -= n;
                curN = f;
            } else {
                List<Pair> remain = new ArrayList<>(
                    food.subList(i, total)
                );

                remain.sort(Comparator.comparingInt(p -> p.idx));

                int next = (int) (k % (total - i));

                answer = remain.get(next).idx + 1;
                return answer;
            }
        }

        return -1;
    }
}

class Pair implements Comparable<Pair> {
    int idx;
    int f;

    Pair(int idx, int f) {
        this.idx = idx;
        this.f = f;
    }

    @Override
    public int compareTo(Pair p) {
        if (this.f != p.f) {
            return Integer.compare(this.f, p.f);
        }

        return Integer.compare(this.idx, p.idx);
    }
}