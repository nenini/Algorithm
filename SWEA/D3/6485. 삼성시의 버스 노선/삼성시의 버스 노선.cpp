#include <bits/stdc++.h>
using namespace std;
// 22:23
int T;
int dp[5002];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for (int test = 1; test <= T; test++) {
        int N;
        cin >> N;
        memset(dp,0,sizeof(dp));
        vector<pair<int, int>> vct;
        vector<int> C;
        for (int i = 0; i < N; i++) {
            int A, B;
            cin >> A >> B;
            vct.push_back(make_pair(A, B));
        }
        for(int i=0;i<N;i++){
            int a=vct[i].first;
            int b=vct[i].second;
            dp[a]++;
            dp[b+1]--;
        }
        for (int i = 1; i <= 5000; i++) {
            dp[i]=dp[i-1]+dp[i];
        }
        int P;
        cin >> P;
        for (int i = 0; i < P; i++) {
            int c;
            cin>>c;
            C.push_back(c);
        }
        cout << "#" << test << " ";
        for (int i = 0; i < P; i++) {
            cout<<dp[C[i]];
            if(i!=P-1){
                cout<< " ";
            }
        }
        cout<<"\n";
    }
}