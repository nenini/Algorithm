#include<iostream>
#include<stack>
using namespace std;
int N;
int arr[1001];
int dp[1001];
int len[1001];
int sum = 0;
int start;
stack <int> stk;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N;i++){
        cin >> arr[i];
        dp[i] = 1;
        len[i] = -1;
    }
    for (int i = 0; i < N;i++){
        for (int j = 0; j < i;j++){
            if(arr[i]>arr[j]&&dp[i]<dp[j]+1){
                dp[i] = dp[j] + 1;
                len[i] = j;
            }
        }
        if(sum<dp[i]){
            sum = dp[i];
            start = i;
        }
    }
    cout << sum << "\n";
    int result=start;
    while (true)
    {
        if(result==-1){
            break;
        }
        stk.push(arr[result]);
        result = len[result];
    }
    while(!stk.empty()){
        cout << stk.top() << " ";
        stk.pop();
    }
}