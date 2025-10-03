#include<bits/stdc++.h>
using namespace std;
long long dp[91];
int N;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    dp[1]=1; dp[2]=1; dp[3]=2;
    for(int i=4;i<=N;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[N];
}