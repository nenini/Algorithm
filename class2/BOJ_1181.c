//qsort 사용법, strcmp, 구조체 사용
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
    char name[50];
    int length;
}word;

int compare(const void *a, const void *b){
    word A = *(word *)a;
    word B = *(word *)b;
    if(A.length>B.length){
        return 1;
    }else if(A.length<B.length){
        return -1;
    }else{
        return (strcmp(A.name, B.name));
    }
}

int N;
int main()
{
    scanf("%d", &N);
    word arr[N];
    for (int i = 0; i < N;i++){
        scanf("%s", arr[i].name);
        arr[i].length = strlen(arr[i].name);
    }
    qsort(arr, N, sizeof(word), compare);
    for (int i = 0; i < N-1;i++){
        if(strcmp(arr[i].name,arr[i+1].name))
            printf("%s\n", arr[i].name);
    }
    printf("%s\n", arr[N-1].name);
}
