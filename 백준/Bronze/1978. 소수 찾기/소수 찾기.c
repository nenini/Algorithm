#include<stdio.h>
int main(void){
    int N;
    int num1=0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int a;
        int num = 0;
        scanf("%d", &a);
        for (int j = 1; j <= a;j++){
            if(a%j==0){
                num++;
            }
        }
        if(num==2){
            num1++;
        }
    }
    printf("%d\n",num1);

}