#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int test = 1; test <= 10; test++) {
        int N;
        cin>>N;
        string sub;
        string str;
        cin>>sub;
        cin>>str;

        int result=0;

        int sub_size=sub.size();
        int str_size=str.size();
        for (int i = 0; i < str_size-sub_size+1;i++){
            if(sub==str.substr(i,sub_size)){
                result++;
            }
        } 
        cout << "#" << N << " " << result << "\n";
    }
}