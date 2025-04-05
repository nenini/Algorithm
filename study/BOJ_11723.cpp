#include<iostream>
#include<string>
using namespace std;
int M;
int S;
string str;
int num;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> M;
    for (int i = 0; i < M;i++){
        cin >> str;
        if(str=="add"){
            cin >> num;
            num--;
            S |= (1 << num);
        }
        else if (str == "remove")
        {
            cin >> num;
            num--;
            S &= (~(1 << num));
        }
        else if (str == "check")
        {
            cin >> num;
            num--;
            if((S&(1<<num))==0){
                cout << 0<<"\n";
            }else{
                cout << 1<<"\n";
            }
        }
        else if (str == "toggle")
        {
            cin >> num;
            num--;
            S ^= (1 << num);
        }
        else if (str == "all")
        {
            S = INT32_MAX;
        }
        else
        {
            S = 0;
        }
    }
}