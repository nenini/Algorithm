#include<iostream>
using namespace std;
int N, S;
int result=0;
int arr[20];
void function(int num,int sum){
    if(num==N){
        if(sum==S){
            result++;
        }
        return;
    }
    function(num + 1, sum + arr[num]);
    function(num + 1, sum);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> S;
    for (int i = 0; i < N;i++){
        cin >> arr[i];
    }
    if(S==0){
        result--;
    }
    function(0, 0);
    cout << result;
}