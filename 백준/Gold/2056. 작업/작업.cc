#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N;
int result = 0;
vector<int> vct[10001];
int times[10001];
int min_time[10001];
int indegree[10001];

void topology() {
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            min_time[i] = times[i];
            result = max(result, min_time[i]);
        }
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < vct[cur].size(); i++) {
            int next = vct[cur][i];
            min_time[next] = max(min_time[next], min_time[cur] + times[next]);
            result = max(result, min_time[next]);
            if (--indegree[next] == 0) {
                q.push(next);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> times[i];
        int num;
        cin >> num;
        for (int j = 0; j < num; j++) {
            int a;
            cin >> a;
            vct[a].push_back(i);
            indegree[i]++;
        }
    }
    topology();
    
    cout << result;
}