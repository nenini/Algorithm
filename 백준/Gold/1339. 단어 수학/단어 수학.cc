#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int N;
string str;
int alphabet[27];
int num = 9;
int result = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N;i++){
        cin >> str;
        int plus = 1;
        for (int j = str.size()-1; j >=0; j--) {
            alphabet[str[j] - 'A'] += plus;
            plus *= 10;
        }
    }
    sort(alphabet, alphabet + 27,greater<int>());
    for (int i = 0; i < 10; i++) {
        result += alphabet[i] * num;
        num--;
    }
    cout << result;
}