#include <bits/stdc++.h>
using namespace std;
// 22:23
int T;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for (int test = 1; test <= T; test++) {
        int result = 0;
        string input;
        cin >> input;

        string str = "";
        
        for (int i = 0; i<input.length(); i++) {
            str += '0';
        }

        for (int i = 0; i < input.length(); i++) {
            if (input[i] != str[i]) {
                result++;
                for (int j = i; j < input.length(); j++) {
                    if (input[i] == '1') {
                        str[j] = '1';
                    } else {
                        str[j] = '0';
                    }
                }
            }
        }
        cout << "#" << test << " " << result << "\n";
    }
}