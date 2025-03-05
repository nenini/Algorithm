//sum의 자료형 크기 주의하기 N*M으로 longlong 사용
#include<iostream>
#include<algorithm>
using namespace std;
int arr[1000001];
int N, M;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N;i++){
        cin >> arr[i];
    }
    sort(arr, arr + N);
    int start = 0;
    int end = arr[N - 1];
    long long mid;
    int result;
    while (1)
    {
        mid = (start + end) / 2;
        long long sum = 0;
        for (int i = 0; i < N; i++)
        {
            if(arr[i]-mid>0){
                sum += arr[i] - mid;
            }
        }
        if(sum>=M){
            start = mid + 1;
            result = mid;
        }
        else
        {
            end = mid - 1;
        }
        if(start>end){
            break;
        }
    }
    cout << result;
}