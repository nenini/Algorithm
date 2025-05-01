//dp사용
#include<stdio.h>
#define min(a, b) a < b ? a:b
int X;
int arr[1000001];
int main(void)
{
    scanf("%d", &X);
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 1;
    for (int i = 2; i <= X; i++)
    {
        arr[i] = arr[i - 1] + 1;
        if(i%3==0){
            arr[i]=min(arr[i], arr[i / 3] + 1);
        }
        if(i%2==0){
            arr[i]=min(arr[i], arr[i / 2] + 1);
        }
    }
    printf("%d", arr[X]);
}