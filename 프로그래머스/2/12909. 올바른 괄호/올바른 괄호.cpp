#include<bits/stdc++.h>
#include <iostream>

using namespace std;

bool solution(string s)
{
    stack<char> st;
    bool answer = true;

    for(char c:s){
        if(c=='('){
            st.push('(');
        }else{
            if(!st.empty()&&st.top()=='('){
                st.pop();
            }else{
                return false;
            }
        }
    }
    if(!st.empty()) answer=false;
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    // cout << "Hello Cpp" << endl;

    return answer;
}