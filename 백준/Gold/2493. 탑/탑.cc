#include <bits/stdc++.h>
using namespace std;
int N;
stack <pair<int, int> > stc;
int arr[500001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N;i++){
        int num;
        cin >> num;
        while(!stc.empty()&&stc.top().first<num){
            stc.pop();
        }
        if (!stc.empty()) {
            arr[i] = stc.top().second;
        }
        stc.push(make_pair(num, i));
        cout << arr[i] << " ";
    }
}