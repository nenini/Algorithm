#include <bits/stdc++.h>
#define INF (float)1e9
using namespace std;
int N;
vector<pair<int, int> > vct;
double dp[16][1 << 16];
double distance(int startNode, int endNode) {
    double sx = vct[startNode].first;
    double sy = vct[startNode].second;
    double ex = vct[endNode].first;
    double ey = vct[endNode].second;

    return sqrt(pow(ex - sx, 2) + pow(ey - sy, 2));
}

double dfs(int currNode, int currBit) {
    if (currBit == (1 << N) - 1) {
        return distance(currNode, 0);
    }
    if (dp[currNode][currBit] != -1) return dp[currNode][currBit];
    dp[currNode][currBit] = INF;
    for (int i = 0; i < N; i++) {
        if (currBit & 1 << i) continue;
        dp[currNode][currBit] = min(dp[currNode][currBit], distance(currNode,i)+dfs(i,currBit|1<<i));
    }
    return dp[currNode][currBit];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        vct.push_back(make_pair(x, y));
    }
    fill(&dp[0][0], &dp[0][0] + 16 * (1 << 16), -1.0);
    cout.precision(8);
    cout<< dfs(0, 1);
}