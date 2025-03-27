#include<iostream>
#include<string>
using namespace std;
int N;
string arr[64];
void func(int x, int y, int size)
{
    int one = false;
    int zero = false;
    for (int i = x; i < x+size;i++){
        for (int j = y; j < y + size;j++){
            if(arr[i][j]=='1'){
                one = true;
            }else{
                zero = true;
            }
        }
    }
    if(one==zero){
        cout << "(";
        func(x, y, size / 2);
        func(x, y + size / 2, size / 2);
        func(x + size / 2, y, size / 2);
        func(x + size / 2, y + size / 2, size / 2);
        cout << ")";
    }
    else
    {
        if(one==true){
            cout << "1";
        }
        else
        {
            cout << "0";
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N;i++){
        cin >> arr[i];
    }
    func(0, 0, N);
}