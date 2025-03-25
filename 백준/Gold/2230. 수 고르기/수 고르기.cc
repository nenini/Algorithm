#include<iostream>
#include<algorithm>
using namespace std;
int N, M;
int result=0;
int mini = 2000000001;
int arr[100001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    int L = 0, R = 0;
    while(R<N&&L<N){
        result = arr[R] - arr[L];
        if(result>=M){
            mini = min(mini, result);
            L++;
        }
        else
        { // result<M
            R++;
        }
    }
    cout << mini;
}