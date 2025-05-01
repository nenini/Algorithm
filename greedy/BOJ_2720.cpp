#include <bits/stdc++.h>
using namespace std;
int arr[4] = {25, 10, 5, 1};
int sum;
int T;
int C;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for (int i = 0; i < T; i++) {
        sum = 0;
        cin >> C;
        int cnt = 0;
        while (cnt<4) {
            if (arr[cnt] <= C) {
                sum = C / arr[cnt];
                C = C % arr[cnt];
                cout << sum ;
            }else{
                cout << 0 ;
            }
            cnt++;
            if(cnt==4){
                cout << "\n";
            }else{
                cout << " ";
            }
        }
        
    }
}