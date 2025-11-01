#include <bits/stdc++.h>
using namespace std;
bool check;

void print_yes() { cout << "yes" << "\n"; }

void print_no() {
    cout << "no" << "\n";
    check = true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        string str;
        if (!getline(cin, str)) break;
        check = false;
        if (str == ".") {
            break;
        }
        stack<char> st;
        for (char c : str) {
            if (c == '(' || c == '[') {
                st.push(c);
            }else if(c==')'){
                if(st.empty()||st.top()!='('){
                    check =true;
                    break;
                }
                st.pop();
            } else if (c == ']') {
                if (st.empty() || st.top() != '[') {
                    check = true;
                    break;
                }
                st.pop();
            } else if(c=='.'){
                break;
            }
        }
        if(check||!st.empty()) cout<<"no\n";
        else cout<<"yes\n";
    }
}