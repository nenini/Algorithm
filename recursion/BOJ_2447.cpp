#include<iostream>
using namespace std;
int N;
void func(int i,int j, int n)
{
    if(n==1){
        cout << "*";

    }
    else if ((i/(n/3))%3==1&&(j/(n/3))%3==1){
        cout << " ";
    }else{
        func(i, j, n / 3);
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N;i++)
    {
        for (int j = 0; j < N;j++)
        {
            func(i, j, N);
        }
        cout << "\n";
    }
}