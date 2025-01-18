//유클리트 호제법 사용(최대공약수 구하는법)
#include<stdio.h>
int N, M;
int min, max;
int gcd, lcm;
int main()
{
    scanf("%d %d", &N, &M);
    if(N<M){
        min = N;
        max = M;
    }else{
        min = M;
        max = N;

    }
    while (1){
        int remain = max % min;
        if(remain==0){
            gcd = min;
            break;
        }

        max = min;
        min = remain;
    }
    lcm = N * M / gcd;
    printf("%d %d\n", gcd, lcm);
}
