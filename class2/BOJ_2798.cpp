#include <iostream>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    int card[N];
    for (int i = 0; i < N;i++){
        cin >> card[i];
    }
    int sum = 0;
    int result = 0;
    for (int i = 0; i < N - 2; i++)
    {
        for (int j = i + 1; j < N - 1;j++){
            for (int k = j + 1; k < N;k++){
                sum = card[i] + card[j] + card[k];
                if(sum>result && sum<=M){
                    result = sum;
                }
            }
        }
    }
    cout << result;
}