#include<iostream>
#include<queue>
using namespace std;
int N, K;
int main(){
    cin >> N >> K;
    queue<int> queue;
    for (int i = 1; i <=N;i++){
        queue.push(i);
    }
    cout << "<";
    while (!queue.empty())
    {
        for (int i = 1; i <= K;i++){
            if(i==K){
                cout << queue.front();
                queue.pop();
            }else{
                queue.push(queue.front());
                queue.pop();
            }
        }
        if(!queue.empty()){
            cout << ", ";
        }
    }
    cout << ">";

}