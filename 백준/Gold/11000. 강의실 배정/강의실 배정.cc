#include <algorithm>
#include <iostream>
#include <vector>
#include<queue>
using namespace std;

int N, S, T , cnt = 0;
vector<pair<int, int> > v;
// queue<int> q;
priority_queue<int,vector<int>,greater<int> > q;
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S >> T;
        v.push_back(make_pair(S, T));  // 종료시간, 시작시간
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < v.size();i++){
        q.push(v[i].second);
    }
    for (int i = 0; i < v.size(); i++) {
        if(q.top()<=v[i].first){
            q.pop();
        }
    }

    cout << q.size();
}
