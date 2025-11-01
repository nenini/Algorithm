#include <bits/stdc++.h>
using namespace std;

stack<char> st;
int sum;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            st.push(str[i]);
        } else {
            if (str[i - 1] == '(') {
                st.pop();
                sum += st.size();
            } else {
                sum += 1;
                st.pop();
            }
        }
    }
    cout << sum;
}