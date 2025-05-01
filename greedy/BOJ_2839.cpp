#include <bits/stdc++.h>
using namespace std;
int N;
int cnt;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    while(N>=0){
        if(N%5==0){
            cnt += (N / 5);
            cout << cnt;
            return 0;
        } else {
            N -= 3;
            cnt++;
        }
    }
    cout << -1;
}