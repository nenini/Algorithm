#include <bits/stdc++.h>
using namespace std;
int T, N;
vector<string> vct;
int evaluate(string str) {
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    int sum = 0;
    int num = 0;
    bool sign = false; //plus
    bool check = false;  // 정수
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '+' || str[i] == '-') {
            if(sign==false){
                sum += num;
            }else{
                sum -= num;
            }
            num = 0;
            check = true;
            if (str[i] == '+') sign = false;
            else
                sign=true;

        } else if (isdigit(str[i])) {
            if(check==false){
                num =10*num + str[i]-'0';
            }else{
                num = str[i] - '0';
                check = false;
            }
        }
    }
    if (sign == false) {
        sum += num;
    } else {
        sum -= num;
    }
    
    return sum;
}
void dfs(int n, string str, int curr) {
    if (curr == n) {
        if (evaluate(str) == 0) {
            vct.push_back(str);
        }
        return;
    }
    dfs(n, str + '+' + to_string(curr + 1), curr + 1);
    dfs(n, str + '-' + to_string(curr + 1), curr + 1);
    dfs(n, str + ' ' + to_string(curr + 1), curr + 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        vct.clear();
        dfs(N, "1", 1);
        sort(vct.begin(), vct.end());
        for (int i = 0; i < vct.size();i++){
            cout << vct[i] << "\n";
        }
        cout << "\n";
    }
}