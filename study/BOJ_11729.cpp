// 하노이 탑
#include<iostream>
#include <cmath>
using namespace std;
int N;
void hanoi(int num, int a,int b, int c){
    if(num==1){
        cout << a << " " << c<<"\n";
        return;
    }
    hanoi(num - 1, a, c, b);
    hanoi(1, a, b, c);
    hanoi(num - 1, b, a, c);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    cout << (int)pow(2, N) - 1<<"\n";
    //1<<num->2^num
    hanoi(N, 1, 2, 3);
}