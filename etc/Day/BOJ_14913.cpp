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
    if(a==k){
        cout << result;
        return 0;
    }
    while (1)
    {
        result++;
        sum += d;
        if(sum==k){
            cout << result;
            break;
        }
        if(d>0){
            if(sum>k){
                cout << "X";
                break;
            }
        }
        else{
            if(sum<k){
                cout << "X";
                break;
            }
        }
    }
}