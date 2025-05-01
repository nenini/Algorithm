#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s1;
string s2;
int arr[1001][1001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s1;
    cin >> s2;
    for (int i = 1; i <= s1.size();i++){
        for (int j = 1; j <= s2.size();j++){
            if(s1[i-1]==s2[j-1]){
                arr[i][j] = arr[i - 1][j - 1]+1;
            }
            else{
                arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
            }
        }
    }
    cout << arr[s1.size()][s2.size()];
}
