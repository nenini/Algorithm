#include<iostream>
#include<algorithm>
using namespace std;
int N, M;
int arr[500000];
int binary_search(int num){
    int middle;
    int start = 0;
    int end = N - 1;
    while(true){
        middle = (end + start) / 2;
        if (arr[middle] == num || arr[start] == num || arr[end] == num) {
            return 1;
        }
        if(arr[middle]>num){
            end = middle - 1;
        }else{
            start = middle + 1;
        }
        if(start>=end){
            return 0;
        }
    }
}
int main() { 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N;i++){
        cin >> arr[i];
    }
    sort(arr, arr + N);
    cin >> M;
    for (int i = 0; i < M;i++){
        int num;
        cin >> num;
        cout << binary_search(num)<<" ";
    }
}