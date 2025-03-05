#include<stdio.h>
int N;
int arr[128][128];
int white = 0, blue = 0;

void function(int x, int y, int size)
{
    int white_check = 0;
    int blue_check = 0;
    for (int i = x; i < x+size;i++){
        for (int j = y; j < y+size;j++){
            if(arr[i][j]==1){
                blue_check = 1;
            }else{
                white_check = 1;
            }
        }
    }
    if(blue_check==white_check){
        //또 나누기
        function(x, y, size / 2);
        function(x + size / 2, y, size / 2);
        function(x, y + size / 2, size / 2);
        function(x + size / 2, y + size / 2, size / 2);
    }
    else
    {
        if(blue_check ==1){
            blue++;
            return;
        }
        else
        {
            white++;
            return;
        }
    }
}

int main(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N;i++){
        for (int j = 0; j < N;j++){
            scanf("%d", &arr[i][j]);
        }
    }
    function(0, 0, N);
    printf("%d\n", white);
    printf("%d\n", blue);

}