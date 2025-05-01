#include<iostream>
#include<cmath>
using namespace std;
int N, r, c;
int cnt=0;
void z(int x, int y, int size)
{
    if(x==r&&y==c){
        cout << cnt;
        return;
    }
    if(x<=r&&y<=c&&x+size>r&&y+size>c){
        int resize = size / 2;
        z(x, y, resize);
        z(x, y + resize, resize);
        z(x + resize, y, resize);
        z(x + resize, y + resize, resize);
    }else{
        cnt += size * size;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> r >> c;
    int size = pow(2, N);
    z(0, 0, size);
}