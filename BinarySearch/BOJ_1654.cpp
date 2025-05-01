#include<iostream>
#include<algorithm>
using namespace std;
long long K, N;
long long answer;
long long arr[10000];
bool check(int num) {
    long long sum = 0;
    for (int i = 0; i < K;i++){
        sum += arr[i] / num;
        if(sum>=N){
            return true;
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> K >> N;
    for (int i = 0; i < K;i++){
        cin >> arr[i];
    }
    long long middle;
    long long start = 1;
    long long end = *max_element(arr, arr + K);
    while(true){
        middle = (start + end) / 2;
        if(check(middle)){
            start = middle + 1;
            answer = middle;
        }else{
            end = middle - 1;
        }
        if(start>end){
            break;
        }
    }
    cout << answer;
}