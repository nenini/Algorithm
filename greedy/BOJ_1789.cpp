#include <bits/stdc++.h>
using namespace std;
long long N;
int sum;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    int i = 1;
    while(N>0){
        N -= i;
        i++;
        sum++;
    }
    if(N<0){
        sum--;
    }
    cout << sum;
}