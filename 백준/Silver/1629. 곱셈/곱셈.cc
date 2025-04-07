#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll A, B, C;
ll func(ll exponent) {
    if (exponent == 0) return 1;
    ll half = func(exponent / 2);
    ll result = (half * half) % C;
    if (exponent % 2 == 1) {
        return (A * result) % C;
    }
    return result;
}
int main() { 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> A >> B >> C;
    cout<<func(B);
}