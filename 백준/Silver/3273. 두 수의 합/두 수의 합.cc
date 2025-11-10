#include <bits/stdc++.h>
using namespace std;
int n, x;
int a[100001];
int result;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> x;
    sort(a, a + n);
    int start = 0, end = n - 1;
    while (start < end) {
        if (a[start] + a[end] == x) {
            result++;
        }
        if (a[start] + a[end] <= x) {
            start++;
        }else{
            end--;
        }
    }
    cout<<result;
}