//윈도우 슬라이드 알고리즘
#include<stdio.h>
int arr[100001];
int N, M;
int a, b;
int main(void)
{
    scanf("%d %d", &N, &M);
    for (int i=1; i <=N;i++){
        scanf("%d", &arr[i]);
        arr[i] += arr[i - 1];
    }
    for (int i = 0; i < M;i++){
        scanf("%d %d", &a, &b);
        printf("%d\n", arr[b] - arr[a - 1]);
    }
}