#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> prices) {
    stack<int> st;
    int size=prices.size();
        vector<int> answer(size);
    for(int i=0;i<prices.size();i++){
        while(!st.empty()&&prices[st.top()]>prices[i]){
            answer[st.top()]=i-st.top();
            st.pop();
        }
        st.push(i);
    }
    int stack_size=st.size();
    for(int i=0;i<stack_size;i++){
        answer[st.top()]=size-1-st.top();
        st.pop();
    }
    return answer;
}