#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> A;
int opr[4];
int min_num = INT_MAX;
int max_num = INT_MIN;
void dfs(int num, int current) {
    if (num == N - 1) {
        min_num = min(min_num, current);
        max_num = max(max_num, current);
        return;
    }
    for (int i = 0; i < 4;i++){
        if(opr[i]>0){
            int value = current;
            if (i == 0) {
                value += A[num + 1];
            } else if (i == 1) {
                value -= A[num + 1];
            } else if (i == 2) {
                value *= A[num + 1];
            } else {
                value /= A[num + 1];
            }
            opr[i] -= 1;
            dfs(num + 1, value);
            opr[i] += 1;
        }
    } }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        A.push_back(num);
    }
    for (int i = 0; i < 4; i++) {
        cin >> opr[i];
    }
    dfs(0, A[0]);
    cout << max_num << "\n";
    cout << min_num;
}