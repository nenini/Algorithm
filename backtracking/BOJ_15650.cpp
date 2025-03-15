#include<iostream>
using namespace std;
int N, M;
int arr[9];
void dfs(int num, int m)
{
    if(m==M){
        for (int i = 0; i < M;i++){
            if(i<M-1){
                cout << arr[i] << " ";
            }else{
                cout << arr[i];
            }
        }
        cout << "\n";
    }else{
        for (int i = num; i <= N;i++){
            arr[m] = i;
            dfs(i + 1, m + 1);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    dfs(1, 0);
}