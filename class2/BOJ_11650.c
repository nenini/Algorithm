#include<stdio.h>
#include<stdlib.h>
int N;
typedef struct
{
    int x;
    int y;
}xy;

int compare(const void *a, const void *b)
{
    xy A = *(xy *)a;
    xy B = *(xy *)b;
    if(A.x>B.x){
        return 1;
    }else if (A.x<B.x){
        return -1;
    }else{
        if(A.y>B.y){
            return 1;
        }else{
            return -1;
        }
    }
}
int main(){
    scanf("%d", &N);
    xy arr[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &arr[i].x, &arr[i].y);
    }
    qsort(arr, N, sizeof(xy), compare);
    for (int i = 0; i < N;i++){
        printf("%d %d\n", arr[i].x, arr[i].y);
    }
}