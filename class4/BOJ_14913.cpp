#include<iostream>
using namespace std;
int a, d, k;
int result=1;
int sum=0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> d >> k;
    sum += a;
    while (1)
    {
        result++;
        sum += d;
        if(sum==k){
            cout << result;
            break;
        }if(sum>k){
            cout << "X";
            break;
        }
    }
}