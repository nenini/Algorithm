#include<iostream>
#include<vector>
using namespace std;
int N;
vector<bool> isPrime;
vector<int> vct;
int result = 0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    isPrime.resize(N + 1, true);
    for (int i = 2; i * i <= N; i++)
    {
        if(isPrime[i]){
            for (int j = i * i; j <= N;j+=i){
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <= N;i++){
        if(isPrime[i]){
            vct.push_back(i);
        }
    }
    int L=0, R=0;
    int sum = 0;
    while (true)
    {
        if(sum>N){
            sum -= vct[L];
            L++;
        }else if(R==vct.size()){
            break;
        }else{
            sum += vct[R];
            R++;
        }
        if(sum==N){
            result++;
        }
    }
    cout << result;
}