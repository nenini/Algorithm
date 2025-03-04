// 피보나치를 배열에 미리 저장해서 시간복잡도 줄이기
//dp:동적계획법
#include<stdio.h>

// int fibonacci(int n) {
//     if (n == 0) {
//         return 0;
//     } else if (n == 1) {
//         return 1;
//     } else {
//         return fibonacci(n-1) + fibonacci(n-2);
//     }
// }

int main(){
    int N;
    scanf("%d", &N);
    int num[41][2];
    num[0][0] = 1;
    num[0][1] = 0;
    num[1][0] = 0;
    num[1][1] = 1;

    for (int i = 2; i < 41; i++){
        num[i][0] = num[i - 1][0] + num[i - 2][0];
        num[i][1] = num[i - 1][1] + num[i - 2][1];
    }

    for (int i = 0; i < N; i++){
        int a;
        scanf("%d", &a);
        printf("%d %d\n", num[a][0], num[a][1]);
    }
    
    // return 0;
}

// #include<stdio.h>

// int memo[41];

// int fibonacci(int n) {
//     if (n == 0) return 0;
//     if (n == 1) return 1;
//     if (memo[n] != -1) return memo[n];
//     return memo[n] = fibonacci(n-1) + fibonacci(n-2);
// }

// int main(){
//     int N;
//     scanf("%d", &N);
//     int num[40];
    
//     for (int i = 0; i < 41; i++) {
//         memo[i] = -1;
//     }
    
//     for (int i = 0; i < N; i++){
//         scanf("%d", &num[i]);
//     }
    
//     for (int i = 0; i < N; i++){
//         int n = num[i];
//         int n1 = fibonacci(n);
//         int n2 = (n > 0) ? fibonacci(n - 1) : 0;
//         printf("%d %d\n", n2, n1);
//     }
    
//     return 0;
// }

