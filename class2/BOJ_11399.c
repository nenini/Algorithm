#include<stdio.h>
#include<stdlib.h>
int compare(const void *a, const void *b){
    int A = *(int *)a;
    int B = *(int *)b;
    if(A>B){
        return 1;
    }else if(A<B){
        return -1;
    }else{
        return 0;
    }
}
int sum=0;
int main()
{
    int N;
    scanf("%d", &N);
    int P[N];
    int result[N];
    for (int i = 0; i < N;i++){
        scanf("%d", &P[i]);
    }
    // for (int i = 0; i < N;i++){
    //     printf("%d ", P[i]);
    // }
    qsort(P, N, sizeof(int), compare);
    for (int i = 0; i < N;i++){
        // printf("%d ", P[i]);
        sum += (P[i] * (N - i));
    }
    printf("%d\n", sum);
}