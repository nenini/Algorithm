#include <bits/stdc++.h>
using namespace std;
stack<int> st;
int N;
int arr[100001];
vector<char> vct;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N;i++){
        cin >> arr[i];
    }
    int cnt = 0;
    int i = 1;
    while (cnt<N) {
        if (!st.empty() && st.top() == arr[cnt]) {
            vct.push_back('-');
            st.pop();
            cnt++;
        } else if (i <= N) {
            st.push(i);
            vct.push_back('+');
            i++;
        } else {
            cout << "NO\n";
            return 0;
        }
    }
    for (int i = 0; i < vct.size();i++){
        cout << vct[i]<<"\n";
    }
}