#include<stdio.h>
int N;
int num;
int arr[12];
int main(void)
{
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    scanf("%d", &N);
    for (int i = 4; i <= 11;i++){
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    }
    for (int i = 0; i < N;i++){
        scanf("%d", &num);
        printf("%d\n", arr[num]);
    }
}