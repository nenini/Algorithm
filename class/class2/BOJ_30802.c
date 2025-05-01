#include<stdio.h>
int main(void){
    int N;
    int size[6];
    int T, P;
    int shirt = 0, pen_bundle = 0, pen_each = 0;
    scanf("%d", &N);
    for (int i = 0; i < 6;i++){
        scanf("%d", &size[i]);
    }
    scanf("%d %d", &T, &P);
    for (int i = 0; i < 6;i++){
        int num = size[i] / T;
        if(size[i]!=0){
            if(size[i] % T==0){
                shirt += num;
            }else
                shirt += (num + 1);
        } 
        // if(size[i]<T){
            // if(size[i]!=0){
            //     shirt += (num + 1);
            // } 
        // }else{
        //     shirt += num;
        // }
    }
    pen_bundle = N / P;
    pen_each = N % P;
    printf("%d\n", shirt);
    printf("%d %d\n", pen_bundle, pen_each);
}