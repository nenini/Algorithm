#include <bits/stdc++.h>
using namespace std;
bool arr[26];
int N;
int fun(char c){
    if(c>='A'&&c<='Z'){
        return c - 'A';
    }else if(c>='a'&&c<='z'){
        return c - 'a';
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    cin.ignore();
    for (int i = 0; i < N;i++){
        int num = -1;
        string str;
        // cin >> str;
        getline(cin, str);  // 띄어쓰기 포함 입력
        if(!arr[fun(str[0])]){
            arr[fun(str[0])] = true;
            num = 0;
        }else{
            for (int j = 1; j < str.size();j++){
                if (str[j] != ' ' && str[j - 1] == ' ' && !arr[fun(str[j])]) {
                    arr[fun(str[j])] = true;
                    num = j;
                    break;
                }
            }
            if(num==-1){
                for (int j = 1; j < str.size(); j++) {
                    if (str[j] != ' ' && !arr[fun(str[j])]) {
                        arr[fun(str[j])] = true;
                        num = j;
                        break;
                    }
                }
            }
        }
        for (int j = 0; j < str.size();j++){
            if (num != -1&&num==j) {
                cout << "[" << str[j] << "]";
            }else{
                cout << str[j];
            }
        }
        cout << "\n";
    }
}