#include <bits/stdc++.h>
using namespace std;
string str;
vector<int> vct;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> str;
    for (int i = 0; i < str.size();i++){
        vct.push_back(str[i] - '0');
    }
    sort(vct.begin(), vct.end(), greater<int>());
    for (int i = 0; i < str.size(); i++) {
        cout << vct[i];
    }
}