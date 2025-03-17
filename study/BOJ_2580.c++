#include<iostream>
#include<vector>
using namespace std;
int sudoku[9][9];
vector<pair<int, int> > v;
bool finish=false;
bool check(int num)
{
    for (int i = 0; i < 9;i++){
        if(sudoku[v[num].first][v[num].second]==sudoku[v[num].first][i]&&v[num].second!=i){
            return false;
        }
        if(sudoku[v[num].first][v[num].second]==sudoku[i][v[num].second]&&v[num].first!=i){
            return false;
        }
    }
    int row = v[num].first / 3;
    int col = v[num].second / 3;
    for (int i = row * 3; i < row * 3 + 3;i++){
        for (int j = col * 3; j < col * 3 + 3;j++){
            if( v[num].first!=i||v[num].second!=j){
                if(sudoku[v[num].first][v[num].second]==sudoku[i][j]){
                    return false;
                }
            }
        }
    }
    return true;
}
void function(int num){
    if(num==v.size()){
        for (int i = 0; i < 9;i++){
            for (int j = 0; j < 9;j++){
                if(j<8){
                    cout << sudoku[i][j] << " ";
                }else
                    cout << sudoku[i][j];
            }
            cout << "\n";
        }
        finish = true;
        return;
    }
    for (int i = 1; i <= 9;i++){
        sudoku[v[num].first][v[num].second] = i;
        if (check(num)){
            function(num + 1);
        }
        if(finish){
            return;
        }
        sudoku[v[num].first][v[num].second] = 0;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0;i<9;i++){
        for (int j = 0; j < 9;j++){
            cin>>sudoku[i][j];
            if(sudoku[i][j]==0){
                v.push_back(make_pair(i, j));
            }
        }
    }
    function(0);
}