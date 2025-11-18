#include <bits/stdc++.h>
using namespace std;
char arr[100][100];
bool isPalindrome(int start, int len, bool check,int index) {

    for (int i = 0; i < len / 2; i++) {
        if(check){
            if (arr[index][start + i] != arr[index][start + len - i - 1]) {
                return false;
            }
        }else{
            if (arr[start + i][index] != arr[start + len - i - 1][index]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int test = 1; test <= 10; test++) {
        int result = 0;
        int N;
        cin >> N;
        for (int i = 0; i < 100; i++) {
            string str;
            cin>>str;
            for (int j = 0; j < 100; j++) {
                arr[i][j] = str[j];
            }
        }
        for(int j=0;j<100;j++){
            bool found = false;
            for (int len = 100; len >= 1; len--) {
                for (int i = 0; i + len <= 100; i++) {
                    if(isPalindrome(i, len, true,j)){
                        result=max(len,result);
                        found=true;
                        break;
                    }
                }
                if (found) break;
            }
        }
        for (int j = 0; j < 100; j++) {
            bool found = false;
            for (int len = 100; len >= 1; len--) {
                for (int i = 0; i + len <= 100; i++) {
                    if (isPalindrome(i, len, false, j)) {
                        result = max(len, result);
                        found = true;
                        break;
                    }
                }
                if(found) break;
            }
        }

        cout << "#" << N << " " << result << "\n";
    }
}