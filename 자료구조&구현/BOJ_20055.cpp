#include<bits/stdc++.h>
using namespace std;
int result=1;
int N, K;
int arr[201];  // 내구도 1~2N;
bool robot[101];  // 로봇 위치 1~N;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    for (int i = 1; i <= 2 * N; i++) {
        cin >> arr[i];
    }
    while (true) {
        //1.한칸 회전
        for (int i = 2 * N; i >1; i--) {
            swap(arr[i], arr[i - 1]);
            if(i<=N){
                swap(robot[i], robot[i - 1]);
            }
        }
        robot[1] = false;
        robot[N] = false;
        // 2.벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동
        for (int i = N - 1; i > 1;i--){
            if(arr[i+1]>0&&!robot[i+1]&&robot[i]){
                arr[i + 1] -= 1;
                swap(robot[i + 1], robot[i]);
            }
        }
        // 3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
        if (arr[1] != 0) {  
            robot[1] = true;
            arr[1] -= 1;
        }
        // 4. 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다. 
        //    그렇지 않다면 1번으로 돌아간다.
        int cnt = 0;
        for (int i = 1; i <= 2 * N; i++) {
            if(arr[i]==0){
                cnt++;
            }
        }
        if(cnt>=K){
            cout << result;
            return 0;
        }
        result++;
    }
}