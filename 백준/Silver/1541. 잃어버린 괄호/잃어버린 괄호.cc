#include<bits/stdc++.h>
using namespace std;
string str;
bool check;
int result;
int sum;
int main() {
    cin >> str;
    for (int i = 0; i <=str.size();i++){
        if(str[i]=='-'||str[i]=='+'||i==str.size()){
            if(check){
                result -= sum;
                sum=0;
            }else{
                result += sum;
                sum = 0;
                if (str[i] == '-') check = true;
            }
        }else{
            sum = sum * 10 + str[i]-'0';
        }
    }
    cout << result;
}