#include<stdio.h>
int main(void){
    long a, b, c;
    while (1)
    {
        scanf("%ld %ld %ld", &a, &b, &c);
        if(a==0&&b==0&&c==0)
            break;
        if((a*a+b*b==c*c)||(a*a+c*c==b*b)||((b*b+c*c==a*a))){
            printf("right\n");
        }else{
            printf("wrong\n");
        }
    }
    
}