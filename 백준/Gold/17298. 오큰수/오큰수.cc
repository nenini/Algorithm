#include <bits/stdc++.h>
using namespace std;

int arr[1000001];
int result[1000001];
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    stack<int> st;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        result[i] = -1;
    }

    for (int i = 0; i < N; i++) {
        while(!st.empty()&&arr[i]>arr[st.top()]){
            result[st.top()]=arr[i];
            st.pop();
            
        }
        st.push(i);
    }
    for (int i = 0; i < N; i++) {
        cout << result[i] << " ";
    }
}