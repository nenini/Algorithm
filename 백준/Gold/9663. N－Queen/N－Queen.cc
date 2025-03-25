#include<iostream>
using namespace std;
int N;
bool visited[15];
bool diagonal1[30], diagonal2[30];
int result = 0;
void nQueen(int row)
{
    if(row==N){
        result++;
        return;
    }
    for (int i = 0; i < N;i++){
        if(!visited[i]&&!diagonal1[row+i]&&!diagonal2[row-i+N]){
            visited[i] = true;
            diagonal1[row+i] = true;
            diagonal2[row - i + N] = true;
            nQueen(row + 1);
            visited[i] = false;
            diagonal1[row+i] = false;
            diagonal2[row - i + N] = false;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    nQueen(0);
    cout << result;
}