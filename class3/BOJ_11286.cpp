//최대값 힙
#include<iostream>
#include<queue>
// #include<cmath>
using namespace std;
int N;
int x;
struct cmp{
    bool operator()(int first, int second) {
		if (abs(first) > abs(second)) return true;   // 절대값이 작은 것에 우선순위를 높게 주겠다!! -> 일반 sort와 반대로 생각!!
		else if (abs(first) == abs(second)) {
			if (first > second) return true; // 절대값이 같다면 원래 값이 더 작은 것에 우선순위 높게 주겠다
			else return false;
		}
		else return false;
	}
};
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
	priority_queue<int, vector<int>, cmp> p_q;
    cin >> N;
    for (int i = 0; i < N;i++){
        cin >> x;
        if (x == 0){
            if(p_q.empty()){
                cout << 0 <<"\n";
            }else{
                cout <<p_q.top() <<"\n";
                p_q.pop();
            }
        }else{
            p_q.push(x);
        }
    }
}