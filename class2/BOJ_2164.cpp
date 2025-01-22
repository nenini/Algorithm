#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<int> Q;
    int N;
    cin >> N;
    for (int i = 1; i <= N;i++){
        Q.push(i);
    }
    while(Q.size()!=1){
        Q.pop();
        Q.push(Q.front());
        Q.pop();
    }
    cout << Q.front();
}