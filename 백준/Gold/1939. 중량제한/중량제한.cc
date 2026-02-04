#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M;
int visited[10001];  // 현재 섬까지의 가장 큰 값을 저장함
vector<pair<int, int>> vct[10001];

int dijkstra(int a, int b) {
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(INT_MAX, a));
    visited[a] = INT_MAX;
    while (!pq.empty()) {
        int curr = pq.top().second;
        int curr_w = pq.top().first;
        pq.pop();
        if (visited[curr] > curr_w) continue;
        if (curr == b) {
            return visited[curr];
        }
        for (int i = 0; i < vct[curr].size(); i++) {
            int next = vct[curr][i].second;
            int next_w = min(curr_w, vct[curr][i].first);  // 다음까지 이동할때, 중량 최대값
            // 만약 다음 위치에 있는 중량이 더 크면 패스
            if (visited[next] >= next_w) continue;
            visited[next] = next_w;  // 더 큰 중량으로 수정
            pq.push(make_pair(next_w, next));
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        vct[A].push_back(make_pair(C, B));
        vct[B].push_back(make_pair(C, A));
    }
    int island1, island2;
    cin >> island1 >> island2;
    cout << dijkstra(island1, island2);
}