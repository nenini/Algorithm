#include <bits/stdc++.h>
using namespace std;
int N;
long long arr[2000];
int result;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr,arr+N);
    for(int i=0;i<N;i++){
        int L=0, R=N-1;
        while(L<R){
            if(L==i){
                L++;
                continue;
            }
            if (R == i) {
                R--;
                continue;
            }
            if(arr[L]+arr[R]<arr[i]){
                L++;
            }else if(arr[L]+arr[R]>arr[i]){
                R--;
            }else{
                result++;
                break;
            }
        }
    }
    cout<<result;
}