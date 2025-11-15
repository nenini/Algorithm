#include <bits/stdc++.h>

using namespace std;


int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    for (int test = 1; test <= 10; test++) {
        int testnum;
        cin>>testnum;
        queue<int> q;
        for(int i=0;i<8;i++){
            int num;
            cin>>num;
            q.push(num);
        }
        bool check=true;
        while(check){
            for(int i=1;i<=5;i++){
                int num = q.front();
                q.pop();
                num -= i;
                if (num <= 0) {
                    q.push(0);
                    check=false;
                    break;
                }
                q.push(num);
            }
        }
        cout<<"#"<<test<<" ";
        for (int i = 0; i < 8; i++) {
            cout<<q.front()<<" ";
            q.pop();
        }
        cout<<"\n";
    }

    return 0;  // 정상종료시 반드시 0을 리턴해야합니다.
}