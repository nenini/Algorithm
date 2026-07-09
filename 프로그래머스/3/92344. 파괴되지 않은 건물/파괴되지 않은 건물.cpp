#include <string>
#include <vector>

using namespace std;
int sum[1001][1001];

void game(int type, int r1,int c1,int r2,int c2,int degree){
    if(type==1) degree*= -1;
    sum[r1][c1]+=degree;
    sum[r1][c2+1]-=degree;
    sum[r2+1][c1]-=degree;
    sum[r2+1][c2+1]+=degree;
}

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    for(int i=0;i<skill.size();i++){
        
        int type=skill[i][0];
        int r1=skill[i][1];
        int c1=skill[i][2];
        int r2=skill[i][3];
        int c2=skill[i][4];
        int degree=skill[i][5];
        
        game(type,r1,c1,r2,c2,degree);
        
    }
    for(int r=0;r<board.size();r++){
        for (int c = 1; c < board[r].size(); c++) {
            sum[r][c] += sum[r][c - 1];
        }
    }
    
    for(int c=0;c<board[0].size();c++){
        for(int r=1;r<board.size();r++){
            sum[r][c]+=sum[r-1][c];
        }
    }
    
    for(int r=0;r<board.size();r++){
        for(int c=0;c<board[0].size();c++){
            if(board[r][c]+sum[r][c]>0){
                answer++;
            }
        }
    }
    
    return answer;
}