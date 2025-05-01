#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int N, M;
typedef struct{
    char name[20];
} people;
int compare(const void *a, const void *b){
    return (strcmp(((people *)a)->name, ((people *)b)->name));
}

int main()
{
    scanf("%d %d", &N, &M);
    people *arr = (people *)malloc((N + M) * sizeof(people));
    for (int i = 0; i < N+M; i++)
    {
        scanf("%s", arr[i].name);
    }
    qsort(arr, N + M, sizeof(people), compare);
    int result=0;
    people *name = (people *)malloc((N + M) * sizeof(people));
    for (int i = 0; i < N + M-1; i++)
    {
        if(strcmp(arr[i].name,arr[i+1].name)==0){
            strcpy(name[result].name, arr[i].name);
            result++;
            i++;
        }
    }
    printf("%d\n", result);
    for (int i = 0; i < result;i++){
        printf("%s\n", name[i].name);
    }
}