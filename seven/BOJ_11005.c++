#include <iostream>
#include <stack>
using namespace std;
int main(void){
    int N;
    int B;
    int remain=1;
    stack <char> result;
    cin >> N >> B;
    while (1)
        {
            int N_old=N;
            N = N / B;
            
            remain = N_old - N * B;
            if (remain >= 0 && remain <= 9)
            {
                result.push(remain + '0');
            }
            if (remain >= 10 && remain <= 35){
                result.push(remain + 'A' - 10);
            }
            if(N==0){
                break;
            }
        }
    while(!result.empty()){
        cout << result.top();
        result.pop();
    }
}