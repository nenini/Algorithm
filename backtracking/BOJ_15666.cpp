#include<iostream>
#include<algorithm>
using namespace std;
int N, M;
int arr[9];
int visited[9];
int input[9];
void dfs(int m,int num){
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
        int x = 0;
        for (int i = num; i < N; i++)
        {
            if(input[i]!=x){
                x = input[i];
                arr[m] = input[i];
                dfs(m + 1,i); 
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < N;i++){
        cin >> input[i];
    }
    sort(input, input + N);
    dfs(0,0);
}
