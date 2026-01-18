#include <bits/stdc++.h>
using namespace std;
float startX, startY;
float destX, destY;
vector<pair<float, float>> cannon;
float dist[102];
int n;

float a1, b1, a2, b2, distan, min_time;

void dijstra() {
    priority_queue<pair<float, int>, vector<pair<float, int>>, greater<pair<float, int>>> pq;
    dist[0] = 0;
    pq.push(make_pair(0.0, 0));
    while (!pq.empty()) {
        int ci = pq.top().second;
        float ctime = pq.top().first;
        pq.pop();
        if (ci == n + 1) break;
        if (dist[ci] < ctime) continue;
        for (int i = 1; i <= n + 1; i++) {
            if (i != ci) {
                a1 = cannon[ci].first;
                b1 = cannon[ci].second;
                a2 = cannon[i].first;
                b2 = cannon[i].second;
                float dx = a1 - a2, dy = b1 - b2;
                distan = sqrt(dx * dx + dy * dy);
                if (ci == 0)
                    min_time = distan / 5.0;
                else
                    min_time = min(distan / 5.0, abs(distan - 50.0) / 5 + 2);

                if (ctime + min_time < dist[i]) {
                    dist[i] = ctime + min_time;
                    pq.push(make_pair(ctime + min_time, i));
                }
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> startX >> startY;
    cin >> destX >> destY;
    cin >> n;
    cannon.push_back(make_pair(startX, startY));
    for (int i = 0; i < n; i++) {
        float X, Y;
        cin >> X >> Y;
        cannon.push_back(make_pair(X, Y));
    }
    fill(dist, dist + n + 2, FLT_MAX);
    cannon.push_back(make_pair(destX, destY));

    dijstra();
    cout << dist[n + 1];
}