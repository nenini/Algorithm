#include<iostream>
#include<cstring>
#include<algorithm>
#define INF (int)1e9
using namespace std;
int C,N;
int cost[20];
int customer[20];
int dp[1001+100];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>C>>N;
    for(int i=0;i<N;i++){
        cin>>cost[i]>>customer[i];
    }
    fill(dp,dp+1101,INF);
    dp[0]=0;
    for(int i=0;i<N;i++){
        for(int j=0;j+customer[i]<=1100;j++){
            if(dp[j]==INF) continue;
            dp[j + customer[i]] = min(dp[j + customer[i]],dp[j]+cost[i]);
        }
    }
    int result=INF;
    for(int i=C;i<=1100;i++){
        result=min(dp[i],result);
    }
    cout<<result;
}