#include <bits/stdc++.h>
using namespace std;
int N, K;
vector<int> bag;
vector<pair<int, int> > gem;
long long sum;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int M, V;
        cin >> M >> V;
        gem.push_back(make_pair(M, V));
    }
    sort(gem.begin(), gem.end());

    for (int i = 0; i < K; i++) {
        int C;
        cin >> C;
        bag.push_back(C);
    }
    sort(bag.begin(), bag.end());
    priority_queue<int> pq;
    int index = 0;
    for (int i = 0; i < K; i++) {
        while (true) {
            if (index < N && gem[index].first <= bag[i]) {
                pq.push(gem[index].second);
                index++;
            }else{
                break ;
            }
        }
        if (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }
    cout << sum;
}