//최소힙->우선순위큐로 구현(큰 수가 우선순위가 높아서 음수를 곱해서 적용)
#include<iostream>
#include<queue>
using namespace std;
int N;
int x;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    priority_queue <int> p_q;
    cin >> N;
    for (int i = 0; i < N;i++){
        cin >> x;
        if (x == 0){
            if(p_q.empty()){
                cout << 0 <<"\n";
            }else{
                cout << (-1) * p_q.top() <<"\n";
                p_q.pop();
            }
        }else{
            p_q.push((-1) * x);
        }
    }
}