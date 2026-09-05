import java.util.*;

class Solution {
    public String[] solution(String[][] plans) {
        int size = plans.length;
        String[] answer = new String[size];
        int idx = 0;

        Task[] tasks = new Task[size];

        // 1. plans -> Task 변환
        for (int i = 0; i < size; i++) {
            String name = plans[i][0];
            String start = plans[i][1];
            String time = plans[i][2];

            String[] split = start.split(":");
            int hour = Integer.parseInt(split[0]);
            int minute = Integer.parseInt(split[1]);

            int startInt = hour * 60 + minute;
            int t = Integer.parseInt(time);

            tasks[i] = new Task(name, startInt, t);
        }

        // 2. 시작 시간 순 정렬
        Arrays.sort(tasks, (a, b) ->
            Integer.compare(a.start, b.start)
        );

        // 멈춘 과제 저장
        Deque<Task> stack = new ArrayDeque<>();

        // 3. 과제 처리
        for (int i = 0; i < size - 1; i++) {
            Task current = tasks[i];
            Task next = tasks[i + 1];

            // 현재 과제를 할 수 있는 시간
            int available = next.start - current.start;

            // 현재 과제를 다음 과제 시작 전에 끝낼 수 있음
            if (current.remain <= available) {
                answer[idx++] = current.name;

                // 남은 시간 동안 멈춘 과제 처리
                int leftTime = available - current.remain;

                while (leftTime > 0 && !stack.isEmpty()) {
                    Task stopped = stack.pop();

                    // 멈춘 과제도 끝낼 수 있음
                    if (stopped.remain <= leftTime) {
                        leftTime -= stopped.remain;
                        answer[idx++] = stopped.name;
                    }

                    // 다 못 끝냄
                    else {
                        stopped.remain -= leftTime;
                        stack.push(stopped);
                        leftTime = 0;
                    }
                }
            }

            // 다음 과제가 시작해서 현재 과제를 중단해야 함
            else {
                current.remain -= available;
                stack.push(current);
            }
        }

        // 4. 마지막 과제는 더 이상 새 과제가 없으므로 무조건 끝냄
        answer[idx++] = tasks[size - 1].name;

        // 5. 멈춰둔 과제를 최근 순서대로 완료
        while (!stack.isEmpty()) {
            answer[idx++] = stack.pop().name;
        }

        return answer;
    }
}

class Task {
    String name;
    int start;
    int remain;

    Task(String name, int start, int remain) {
        this.name = name;
        this.start = start;
        this.remain = remain;
    }
}