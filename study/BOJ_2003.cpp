#include<iostream>
#include<vector>
using namespace std;
int N, M;
int arr[10001];
int result=0;
int sum = 0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N;i++){
        cin >> arr[i];
    }
    int R=0, L=0;
    while(true){
        if(sum>=M){
            sum -= arr[L++];
        }else if(R==N){
            break;
        }else{
            sum += arr[R++];
        }
        if(sum==M){
            result++;
        }
    }
    cout << result;
}