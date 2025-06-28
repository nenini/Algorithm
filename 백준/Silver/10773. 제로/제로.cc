#include <bits/stdc++.h>
using namespace std;
stack<int> stc;
int K;
int sum;
int main() {
    cin >> K;
    while (K--) {
        int a;
        cin >> a;
        if(a==0){
            stc.pop();
        }else{
            stc.push(a);
        }
    }
    while(!stc.empty()){
        sum += stc.top();
        stc.pop();
    }
    cout << sum;
}