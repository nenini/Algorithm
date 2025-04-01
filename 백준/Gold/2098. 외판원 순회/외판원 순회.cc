#include<iostream>
#include<cstring>
#define INF 18000000;
using namespace std;
int N;
int arr[16][16];
int dp[16][1 << 16];
int dfs(int curNode,int curBit){
    if(curBit==(1<<N)-1){
        if(arr[curNode][0]!=0){
            return arr[curNode][0];
        }else{
            return INF; //길이 없는 경우
        }
    }
    if(dp[curNode][curBit]!=-1){
        return dp[curNode][curBit];
    }
    dp[curNode][curBit] = INF;
    for (int i = 0; i < N; i++)
    {
        if((curBit&(1<<i))) continue;
        if(arr[curNode][i]==0)continue;
        dp[curNode][curBit] = min(dp[curNode][curBit], arr[curNode][i] + dfs(i, (curBit | 1 << i)));
    }
    return dp[curNode][curBit];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N;i++){
        for (int j = 0; j < N;j++){
            cin >> arr[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout<<dfs(0, 1);
}