#include<iostream>
#include<algorithm>
using namespace std;
long long N;
long long result[3];
long long arr[5001];
long long sum = 1e18;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N;i++){
        cin >> arr[i];
    }
    sort(arr, arr + N);
    long long L, R;
    for (int i = 0; i < N - 2; i++)
    {
        L = i + 1;
        R = N - 1;
        while(L<R){
            long long sum1 = arr[i] + arr[L] + arr[R];
            if (sum>abs(sum1)){
                sum = abs(sum1);
                result[0] = arr[i];
                result[1] = arr[L];
                result[2] = arr[R];
            }
                if(sum1<0){
                    L++;
                }
                else
                {
                    R--;
                }
            
        }
    }
    cout << result[0] << " " << result[1] << " " << result[2];
}