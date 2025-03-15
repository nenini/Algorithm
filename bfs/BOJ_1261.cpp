#include<iostream>
using namespace std;
int M, N;
string input;
int arr[101][101][2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> M >> N;
    for (int i = 0; i < N;i++){
        cin >> input;
        for (int j = 0; j < M;j++){
            arr[i][j][0] = input[j] - '0';
        }
    }
    
}