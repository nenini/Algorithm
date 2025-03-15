#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[9];
int input[9];
bool visited[9]; // 방문 여부 체크

void dfs(int m) {
    if (m == M) { // M개의 숫자 선택 완료
        for (int i = 0; i < M; i++) {
            if(i<M-1){
                cout << arr[i] << " ";
            }else{
                cout << arr[i];
            }
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < N; i++) { // 모든 원소를 순열로 선택
        if (!visited[i]) { // 아직 선택되지 않은 숫자만 선택
            visited[i] = true;
            arr[m] = input[i];
            dfs(m + 1);
            visited[i] = false; // 백트래킹
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> input[i];
    }

    sort(input, input + N); // 사전순 출력을 위해 정렬
    dfs(0); // 순열 생성 시작
}
