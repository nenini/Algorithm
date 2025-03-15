#include<iostream>
using namespace std;
int N, M;
int arr[9];
int visited[9];
void dfs(int m)
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
        return ;
    }else{
        for (int i = 1; i <= N;i++){
            // if(!visited[i]){
            //     visited[i] = true;
                arr[m] = i;
                dfs(m + 1);
            //     visited[i] = false;
            // }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin >> N >> M;
    dfs(0);
}