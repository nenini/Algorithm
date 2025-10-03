#include <bits/stdc++.h>
using namespace std;
int N;
vector<pair<int, int> > vct;
int dp[1500001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++){
        int a,b;
        cin>>a>>b;
        vct.push_back(make_pair(a,b));
        dp[i]=0;
    }
    for(int i=0;i<N;i++){
        dp[i+1]=max(dp[i],dp[i+1]);
        if(i+vct[i].first<=N){
            dp[i + vct[i].first] = max(dp[i + vct[i].first],dp[i]+vct[i].second);
        }
    }
    cout<<dp[N];
}