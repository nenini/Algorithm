#include<stdio.h>
#include<stdlib.h>
int N;
int compare(const void *a, const void *b)
{
    int A = *(int *)a;
    int B = *(int *)b;
    if(A>B){
        return 1;
    }else{
        return -1;
    }
}
int main(){
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N;i++){
        scanf("%d", &arr[i]);
    }
    qsort(arr, N, sizeof(int), compare);
    for (int i = 0; i < N;i++){
        printf("%d\n", arr[i]);
    }
}