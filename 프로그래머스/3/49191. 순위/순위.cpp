#include <string>
#include <vector>

using namespace std;
bool win[101][101];
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for(int i=0;i<results.size();i++){
        int a=results[i][0];
        int b=results[i][1];
        win[a][b]=true;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(win[i][k]&&win[k][j]) win[i][j]=true;
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        int win_cnt=0;
        int lose_cnt=0;
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if(win[i][j]) win_cnt++;
            if(win[j][i]) lose_cnt++;
        }
        if(win_cnt+lose_cnt==n-1) answer++;
    }
    return answer;
}