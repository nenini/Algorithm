#include <iostream>
#include <queue>
using namespace std;
int N;
int result = 0;
priority_queue<int, vector<int>, greater<int> > pq;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    if(N==1){
        cout << 0;
        return 0;
    }
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        pq.push(num);
    }

    while (pq.size() > 1) {
        int sum = 0;
        sum += pq.top();
        pq.pop();
        sum += pq.top();
        pq.pop();
        result += sum;
        pq.push(sum);
    }
    cout << result;
}
