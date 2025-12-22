#include <bits/stdc++.h>
using namespace std;

long long N, K;
long long result;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    long long start = 1, end = N * N;
    while (start <= end) {
        long long middle = (start + end) / 2;
        // 개수 구하기
        long long count = 0;
        for (int i = 1; i <= N; i++) {
            long long num = min(N, middle / i);
            count += num;
        }
        if(count>=K){
            result=middle;
            end=middle-1;
        }else{
            start=middle+1;
        }
    }
    cout<<result;
}