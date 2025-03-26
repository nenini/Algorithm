#include<iostream>
#include<cmath>
using namespace std;
int A, B, C;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> A >> B >> C;
    int result=(int)pow(A, B) % C;
    cout << result;
}