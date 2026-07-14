import java.util.*;

class Solution {
    public int solution(int[] food_times, long k) {
        int[] food = food_times.clone();
        Arrays.sort(food);

        int curN = 0;
        int total = food_times.length;

        for (int i = 0; i < food.length; i++) {
            int f = food[i];

            long n = (long) (total - i) * (f - curN);

            if (n <= k) {
                k -= n;
                curN = f;
            } else {
                long next = k % (total - i);

                for (int j = 0; j < food_times.length; j++) {
                    if (food_times[j] > curN) {
                        if (next == 0) {
                            return j + 1;
                        }

                        next--;
                    }
                }
            }
        }

        return -1;
    }
}