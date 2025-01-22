#include<stdio.h>
int N, M;
int numB = 0;
int numW = 0;
int min = 64;
int main()
{
    scanf("%d %d", &N, &M);
    char arr[N][M];
    getchar();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M;j++){
            scanf("%c", &arr[i][j]);
        }
        getchar();
    }
    for (int i = 0; i < N - 7;i++){
        for (int j = 0; j < M - 7;j++){
            numB = 0;
            numW = 0;
            for (int k = i; k < i+8; k++)
            {
                for (int l = j; l < j+8;l++){
                    if ((k + l)%2==0){ //홀수
                        if(arr[k][l]=='W'){
                            numB++;
                        }else{
                            numW++;
                        }
                    }else{
                        if(arr[k][l]=='B'){
                            numB++;
                        }else{
                            numW++;
                        }
                    }
                }
            }
            min = numW < min ? numW : min;
            min = numB < min ? numB : min;
        }
    }
    printf("%d\n", min);
}