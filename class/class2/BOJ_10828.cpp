#include<iostream>
#include<stack>
using namespace std;
int N;
int main()
{
    stack<int> stack;
    cin >> N;
    int n;
    string command;
    for (int i = 0; i < N;i++){
        cin >> command;
        if(command=="push"){
            cin >> n;
            stack.push(n);
        }else if(command=="pop"){
            if(stack.empty()){
                cout << -1<< endl;
            }else{
                cout << stack.top()<< endl;
                stack.pop();
            }
        }else if(command=="size"){
            cout << stack.size()<< endl;
        }else if(command=="empty"){
            if(stack.empty()){
                cout << 1<< endl;
            }else{
                cout << 0<< endl;
            }
        }else{
            if(stack.empty()){
                cout << -1<< endl;
            }else{
                cout << stack.top()<< endl;
            }
        }
    }
}