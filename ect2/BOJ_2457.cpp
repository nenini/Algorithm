#include <bits/stdc++.h>
using namespace std;
int N;
int arr[100000];
int L, R;
int sum = INT_MAX;
pair<int, int> result;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N;i++){
        cin >> arr[i];
    }
    L = 0;
    R = N - 1;
    while(L<R){
        int temp = arr[L] + arr[R];
        if(abs(temp)<sum){
            sum = abs(temp);
            result = make_pair(arr[L],arr[R]);
        }
        if(temp==0){
            break;
        }else if(temp<0){
            L++;
        }else{
            R--;
        }
    }
    cout << result.first << " " << result.second;
}