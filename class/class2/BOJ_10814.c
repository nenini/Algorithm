#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int age;
    char name[101];
    int num;
} person;

int N;
int compare(const void *a, const void *b){
    person A = *(person *)a;
    person B = *(person *)b;
    if(A.age>B.age){
        return 1;
    }else if(A.age<B.age){
        return - 1;
    }else{
        if(A.num>B.num){
            return 1;
        }else{
            return -1;
        }
    }
}
int main()
{
    scanf("%d", &N);
    person arr[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d %s", &arr[i].age, arr[i].name);
        arr[i].num = i;
    }
    qsort(arr, N, sizeof(person), compare);
    for (int i = 0; i < N;i++){
        printf("%d %s\n", arr[i].age, arr[i].name);
    }
}