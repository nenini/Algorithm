#include<iostream>
#include<queue>
using namespace std;
int N;
int main()
{
    queue<int> queue;
    cin >> N;
    int n;
    string command;
    for (int i = 0; i < N;i++){
        cin >> command;
        if(command=="push"){
            cin >> n;
            queue.push(n);
        }else if(command=="pop"){
            if(queue.empty()){
                cout << -1<< endl;
            }else{
                cout << queue.front()<< endl;
                queue.pop();
            }
        }else if(command=="size"){
            cout << queue.size()<< endl;
        }else if(command=="empty"){
            if(queue.empty()){
                cout << 1<< endl;
            }else{
                cout << 0<< endl;
            }
        }else if(command=="back"){
            if(queue.empty()){
                cout << -1<< endl;
            }else{
                cout << queue.back()<< endl;
            }
        }
        else{
            if(queue.empty()){
                cout << -1<< endl;
            }else{
                cout << queue.front()<< endl;
            }
        }
    }
}