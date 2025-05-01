#include <bits/stdc++.h>
using namespace std;
string S, T;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> S >> T;
    while(T.size()>0){
        if(S==T){
            cout << 1;
            return 0;
        }
        if(T[T.size()-1]=='A'){
            T = T.substr(0, T.size() - 1);
        } else{
            T=T.substr(0, T.size() - 1);
            reverse(T.begin(), T.end());
        }
    }
    cout << 0;
}