#include <bits/stdc++.h>
using namespace std;
string input;
int a_sum = 0;
int sum;
int result;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> input;
    for (int i = 0; i < input.size(); i++) {
        if(input[i]=='a'){
            a_sum++;
        }
    }
    for (int i = 0; i < a_sum;i++){
        if(input[i]=='b'){
            sum++;
        }
    }
    int num = input.size();
    input = input + input;
    result = sum;
    for (int i = 1; i < num; i++) {
        if(input[i-1]=='b'){
            sum--;
        }
        if(input[i+a_sum-1]=='b'){
            sum++;
        }
        result = min(sum, result);
    }
    cout << result;
}