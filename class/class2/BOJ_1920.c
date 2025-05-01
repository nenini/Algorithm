//이진탐색+정렬
//이중 for문 사용시 O(n^2)->이진탐색(log2n)
#include<stdio.h>
#include<stdlib.h>
int N, M;
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
int binarySearch(int A[], int a)
{
    int middle;
    int start = 0;
    int end=N-1;
    while(1){
        middle = (start+end)/2;
        if(A[start]==a||A[end]==a||A[middle]==a){
            return 1;
        }
        if(a<A[middle]){
            end = middle - 1;
        }
        else
        {
            start = middle + 1;
        }
        if(start>=end){
            return 0;
        }
    }
    

}
int main()
{
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N;i++){
        scanf("%d", &A[i]);
    }
    qsort(A, N, sizeof(int), compare);
    scanf("%d", &M);
    int B[M];
    int result[M];
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &B[i]);
        printf("%d\n", binarySearch(A,B[i]));
    }
}