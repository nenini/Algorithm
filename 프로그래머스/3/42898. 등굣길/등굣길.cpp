#include <string>
#include <vector>
#define MOD 1000000007

using namespace std;
bool arr[101][101];
int dp[101][101];
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    for(int i=0;i<puddles.size();i++){
        arr[puddles[i][0]][puddles[i][1]]=true;
    }
    dp[1][1]=1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(i==1&&j==1) continue;
            if(arr[i][j]) continue;
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
        }
    }
    answer=dp[m][n];
    return answer;
}