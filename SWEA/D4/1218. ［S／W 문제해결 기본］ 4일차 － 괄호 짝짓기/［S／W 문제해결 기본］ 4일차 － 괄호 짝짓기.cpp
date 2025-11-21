#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int test = 1; test <= 10; test++) {
        int N;
        cin >> N;
        bool check = true;
        string str;
        cin >> str;
        stack<int> st;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '(' || str[i] == '<' || str[i] == '{' || str[i] == '[') {
                st.push(str[i]);
            } else {
                if (str[i] == ')') {
                    if (st.top() == '(') {
                        st.pop();
                    } else {
                        check = false;
                        break;
                    }
                }
                if (str[i] == '>') {
                    if (st.top() == '<') {
                        st.pop();
                    } else {
                        check = false;
                        break;
                    }
                }
                if (str[i] == ']') {
                    if (st.top() == '[') {
                        st.pop();
                    } else {
                        check = false;
                        break;
                    }
                }
                if (str[i] == '}') {
                    if (st.top() == '{') {
                        st.pop();
                    } else {
                        check = false;
                        break;
                    }
                }
            }
        }

        cout << "#" << test << " " ;
        if (check) {
            cout << 1;
        }else{
            cout<<0;
        }
        cout << "\n";
    }
}