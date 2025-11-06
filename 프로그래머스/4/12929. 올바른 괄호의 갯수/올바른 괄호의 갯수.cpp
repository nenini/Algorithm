#include <bits/stdc++.h>
int open;
int close;
int result;
using namespace std;
void dfs(stack<char> st){
    if(open==0&&close==0){
        result++;
        return;
    }
    if(open!=0){
        st.push('(');
        open--;
        dfs(st);
        st.pop();
        open++;
    }
    if(!st.empty()&&close!=0&&st.top()=='('){
        st.pop();
        close--;
        dfs(st);
        st.push('(');
        close++;
    }
    
}
int solution(int n) {
    int answer = 0;
    open=n;
    close=n;
    stack<char> emp;
    dfs(emp);
    answer=result;
    
    return answer;
}