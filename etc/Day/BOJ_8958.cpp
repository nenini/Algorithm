#include<iostream>
#include<string>
using namespace std;
string str;
int arr[81];
int N;
int sum=0;
int cnt=1;
int main()
{
    cin >> N;
    for (int i = 0; i < N;i++){
        cin >> str;
        for (int j = 0; j < str.size();j++){
            if(str[j]=='O'){
                sum += cnt;
                cnt++;
            }
            else{
                cnt = 1;
            }
        }
        cout << sum<<"\n";
        cnt = 1;
        sum = 0;
    }
}