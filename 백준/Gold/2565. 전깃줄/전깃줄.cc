#include <bits/stdc++.h>
using namespace std;
int N;
vector<pair<int, int> > vct;
int result;
int dp[501];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        vct.push_back(make_pair(a, b));
    }
    sort(vct.begin(), vct.end());
    for (int i = 0; i < N;i++){
        dp[i] = 1;
        for (int j = 0; j < i;j++) {
            if(vct[j].second<vct[i].second){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int max_num = 0;
    for (int i = 0; i < N;i++){
        max_num = max(dp[i], max_num);
    }

    cout << N-max_num;
}