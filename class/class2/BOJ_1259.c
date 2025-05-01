#include<stdio.h>
#include<string.h>
int main(void){
    char num[5];
    int check = 0;
    while (1)
    {
        check = 0;
        scanf("%s", num);
        if(num[0]=='0'){
            break;
        }
        int len = strlen(num);
        for (int i = 0; i < len / 2;i++){
            if(num[i]!=num[len-i-1]){
                check = 1;
                break;
            }
        }
         if(check==0){
            printf("yes\n");
        }else{
            printf("no\n");
        }
    }
   
}