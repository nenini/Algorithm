#include <bits/stdc++.h>
using namespace std;
string str;
stack<char> st;
queue<char> q;
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        if(str[i]>='A'&&str[i]<='Z'){
            q.push(str[i]);
        } else if (str[i] == '(') {
            st.push(str[i]);
        } else if (str[i] == ')') {
            while(true){
                if(st.top()=='('){
                    st.pop();
                    break;
                }
                q.push(st.top());
                st.pop();
            }
        } else {
            while (!st.empty() && precedence(st.top()) >= precedence(str[i])) {
                q.push(st.top());
                st.pop();
            }
            st.push(str[i]);
        }
    }
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }
    while(!q.empty()){
        cout << q.front();
        q.pop();
    }
}