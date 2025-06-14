#include<bits/stdc++.h>
using namespace std;
int N;
char arr[3100][6200];
void func(int x, int y, int n) {
    if(n==3){
        arr[x][y] = '*';
        arr[x + 1][y - 1] = arr[x + 1][y + 1] = '*';
        for (int i = -2;i<=2;i++){
            arr[x + 2][y + i] = '*';
        }
        return ;
    }
    int half = n / 2;
    func(x, y, half);
    func(x + half, y - half, half);
    func(x + half, y + half, half);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N;i++){
        fill(arr[i], arr[i] + 2 * N - 1, ' ');
    }
    func(0, N - 1, N);
    for (int i = 0; i < N;i++){
        for (int j = 0; j< 2 * N - 1;j++){
            cout<< arr[i][j];
        }
        cout << "\n";
    }
}