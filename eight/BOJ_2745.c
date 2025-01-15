#include <stdio.h>
#include<string.h>
#include<math.h>
int main(void){
    char N[1000];
    int B;
    int N_integer;
    int result=0;
    scanf("%s", N);
    scanf("%d", &B);
    int len = strlen(N);
    for (int i = 0; i < len;i++){
        if('0'<=N[i]&&N[i]<='9'){
            N_integer = N[i] - '0';
        }
        if('A'<=N[i]&&N[i]<='Z'){
            N_integer=N[i] - 'A'+10;
        }
        result += N_integer *pow(B ,(len - 1 -i));
    }
    printf("%d\n", result);
}