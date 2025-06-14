#include <bits/stdc++.h>
using namespace std;
string S, T;
bool check;
bool dfs(string t){
    if (t==S){
        return true;
    }
    if(t.length()<S.length()){
        return false;
    }
    if (t.back() == 'A') {
        string next = t;
        next.pop_back();
        check |= dfs(next);
    }
    if(t.front()=='B'){
        string next = t;
        reverse(next.begin(), next.end());
        next.pop_back();
        check |= dfs(next);
    }
    return check;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> S >> T;
    if (dfs(T)){
        cout << "1";
    }else{
        cout << "0";
    }
}