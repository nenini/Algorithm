#include<stdio.h>
int N, K;
int factorial(int f){
    if(f<=1){
        return 1;
    }else{
        return f * factorial(f - 1);
    }
}
int main(void)
{
    scanf("%d %d", &N, &K);
    printf("%d\n", factorial(N) / (factorial(N - K) * factorial(K)));
}