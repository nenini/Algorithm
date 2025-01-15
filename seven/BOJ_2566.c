#include<stdio.h>
int main(void){
    int num[9][9];
    int max=0;
    int row;
    int col;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9;j++){
            scanf("%d", &num[i][j]);
            if(num[i][j]>=max){
                max = num[i][j];
                row = i;
                col = j;
            }
        }
    }
    printf("%d\n", max);
    printf("%d %d\n", row+1, col+1);
}