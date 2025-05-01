#include<bits/stdc++.h>
using namespace std;
int N, C;
int x[200000];
int last;
int answer;
bool check(int num) {
    int sum = 1;
    int num1=x[0];
    for (int i = 1; i < N; i++) {
        if (x[i] - num1 >= num) {
            sum++;
            num1 = x[i];
            if (sum == C) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> C;
    for (int i = 0; i < N;i++){
        cin >> x[i];
    }
    sort(x, x + N);
    int middle;
    int start = 1;
    int end = x[N - 1] - x[0];
    while(start<=end){
        middle = (start + end) / 2;
        if(check(middle)){
            answer = middle;
            start = middle + 1;
        } else {
            end = middle - 1;
        }
    }
    cout << answer;
}