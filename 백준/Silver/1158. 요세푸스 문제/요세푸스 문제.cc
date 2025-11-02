#include <bits/stdc++.h>
using namespace std;
int N, K;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>K;
    queue<int> q;
    for(int i=1;i<=N;i++){
        q.push(i);
    }
    cout<<"<";
    for(int i=0;i<N;i++){
        for(int j=0;j<K;j++){
            if(j==K-1){
                cout<<q.front();
                q.pop();
            }else{
                q.push(q.front());
                q.pop();
            }
        }
        if(!q.empty()) cout<<", ";
    }
    cout<<">";
}