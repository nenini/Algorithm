#include<iostream>
using namespace std;
int check = true;
int N;
int dp_front[1001];
int dp_back[1001];
int arr[1001];
int sum = 0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N;i++){
        cin>>arr[i];
        dp_front[i] = 1;
        dp_back[i] = 1;
    }
    for (int i = 0; i < N;i++){
        for (int j = 0; j < i;j++){
            if(arr[i]>arr[j]){
                dp_front[i] = max(dp_front[i], dp_front[j] + 1);
            }
        }
    }
    
    for (int i = N-1; i >=0;i--){
        for (int j = N-1; j > i;j--){
            if(arr[i]>arr[j]){
                dp_back[i] = max(dp_back[i], dp_back[j] + 1);
            }
        }
    }
    for (int i = 0; i < N;i++){
        sum = max(dp_front[i] + dp_back[i], sum);
    }
    cout << sum - 1;
}
